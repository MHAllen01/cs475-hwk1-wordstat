/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: dchiu
 */
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"

/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Ignore
 * @return int
 */
int main(int argc, char *argv[])
{
	// TODO: start by getting strings from users until # is input
	char inputStrings[MAX_INPUT_LEN];

	printf("Enter strings (# to stop):\n");

	int counter = 0;
	int optionCounter = 0;

	while (counter == 0) {
		// Grab the strings from the user with fgets
		fgets(inputStrings, MAX_INPUT_LEN, stdin);

		// Process the strings and store in a global array to remember
		ProcessInput(inputStrings);

		// TODO: after # is input, print menu options
		if (inputStrings[0] == '#' && inputStrings[1] == '\n') {
			optionCounter = 0;
			while (optionCounter == 0) {
				int userNum = GetMenuOption();

				if (userNum == 1) {
					// User input is 1 (show word stats)
					GetStats();
				}
				else if (userNum == 2) {
					// User input is 2 (show the histogram)
					ShowHistogram();
				}
				else if (userNum == 3) {
					// User input is 3 (accept more strings)
					printf("Enter strings (# to stop):\n");
					optionCounter = 1;
				}
				else if (userNum == 4) {
					// User input is 4 (quit)
					optionCounter = 1;
					counter = 1;
				} else {
					// User input is unknown (prompt for input again);
					printf("Error: Unknown option %d.\n\n", userNum);
				}
			}
		}
	}

	printf("Exiting...\n");
	return 0;
}
