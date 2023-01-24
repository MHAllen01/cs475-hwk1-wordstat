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
int main(int argc, char *argv[]) {
	// declare and initialize the histogram
	//int histogram[ALPHABET_SIZE];

	// TODO: start by getting strings from users until # is input
	char inputStrings[MAX_INPUT_LEN];

	printf("Enter strings (# to stop):\n");
	while(strcmp(inputStrings, "#") != 0) {
		fgets(strtok(inputStrings, "\n"), MAX_INPUT_LEN, stdin);
	}
	// TODO: after # is input, print menu options
	if (strcmp(inputStrings, "#") == 0) {
		getMenuOption();
	}
	printf("Exiting...\n");
	return 0;
}
