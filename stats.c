/*
 * histo.c
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "defs.h"
#include "stats.h"

// TODO: function definitions for dealing with histogram below

char tempConcatString[MAX_INPUT_LEN];   // Global variable to keep track of passed in Strings
int tempIdx = 0;                        // Global variable to keep track of current index in the temporary array
char vowels[MAX_INPUT_LEN];             // Global variable to keep track of vowels for stat calculation
char consonants[MAX_INPUT_LEN];         // Global variable to keep track of consonants for stat calculation

void ProcessInput(char passedStrings[MAX_INPUT_LEN]) {
    int index = 0;

    for (int i=0; i<strlen(passedStrings); i++) {

        if (isalpha(passedStrings[i])) {
            // Remember the last index while saving a lower case letter
            tempConcatString[tempIdx + index] = tolower(passedStrings[i]);
            index++;

        }
    }

    // Increment the index for next string
    tempIdx += index;
}

void GetStats() {
    int vowelIdx = 0;       // Index for the vowels array
    int consonantIdx = 0;   // Index for the consonants array

    for (int i=0; i<strlen(tempConcatString); i++) {
        if (tempConcatString[i] == 'a' || tempConcatString[i] == 'e' || tempConcatString[i] == 'i' || tempConcatString[i] == 'o' || tempConcatString[i] == 'u') {
            // See if letter is a vowel
            vowels[vowelIdx] = tempConcatString[i];
            vowelIdx++;
        } else {
            // See if letter is a consonant
            consonants[consonantIdx] = tempConcatString[i];
            consonantIdx++;
        }
    }

    // Variables used for calculating the totals (makes the printf look nicer)
    int numVowels = strlen(vowels);
    int numConsonants = strlen(consonants);
    int total = numVowels + numConsonants;

    float vowelPercent = ((float) numVowels / total) * 100;
    float consonantPercent = ((float) numConsonants / total) * 100;

    printf("\nVowels = %d (%.2f%%), Consonants = %d (%.2f%%), Total = %d\n\n", numVowels, vowelPercent, numConsonants, consonantPercent, total);
}

void ShowHistogram() {
    // Get the frequency of each letter. Array is organized by the letter's alphabetical position
    int letterFrequency[ALPHABET_SIZE];

    // Initialize every cell to 0
    for (int i=0; i<ALPHABET_SIZE; i++) {
        letterFrequency[i] = 0;
    }

    for (int i=0; i<strlen(tempConcatString); i++) {
        // Get the alphabet position
        int idx = tempConcatString[i] - 'a';

        // Increment the position's frequency
        letterFrequency[idx]++;
    }

    // Get the highest letter frequency
    int highestFrequency = 0;
    for (int i=0; i<ALPHABET_SIZE; i++) {
        if (letterFrequency[i] > highestFrequency) {
            // The highest frequency will be replaced if there is a higher frequency
            highestFrequency = letterFrequency[i];
        }
    }

    // Print the * character for each frequency if there is a valid option
    for (int i=highestFrequency; i > 0; i--) {
        // See if the letter at the corresponding j is greater than or equal to i by decrementing from the highest frequency
        for (int j=0; j<ALPHABET_SIZE; j++) {

            // Print horizontally across
            if (letterFrequency[j] >= i) {
                // True, so print *
                printf("* ");
            } else {
                // Not true, so print empty spaces
                printf("  ");
            }
        }
        printf("\n");
    }

    // Print the alphabet
    printf("a b c d e f g h i j k l m n o p q r s t u v w x y z\n");

    // Print the frequency amounts
    for (int i=0; i<ALPHABET_SIZE; i++) {
        printf("%d ", letterFrequency[i]);
    }
    printf("\n\n");
}