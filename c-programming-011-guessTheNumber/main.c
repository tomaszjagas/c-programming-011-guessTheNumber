/******************************************
* Description: Simple guess the number game
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for random number generator seed

int main() {
	int randomNumber = 0;
	int guess = 0;
	int NumberOfGuesses = 5;
	time_t t;

	// initialization for random number generator
	srand((unsigned)time(&t));

	// get the random number
	randomNumber = rand() % 21;

	printf("\nThis is a guessing game.");
	printf("\nI've chosen the number between 0-20, which you must guess.\n");

	for (NumberOfGuesses = 5; NumberOfGuesses > 0; --NumberOfGuesses) {
		printf("\nYou have %d tr%s left.", NumberOfGuesses, NumberOfGuesses == 1 ? "y" : "ies");
		printf("\nEnter a guess: ");
		scanf_s("%d", &guess);

		if (guess == randomNumber) {
			printf("\nCongrats. You guessed it!\n");
			return;
		}
		else if (guess < 0 || guess>20) { // checking for an invalid guess
			printf("I said the number is between 0 and 20.\n");
		}
		else if (randomNumber > guess) {
			printf("Sorry, %d is wrong, My number is greater than that.\n", guess);
		}
		else if (randomNumber < guess) {
			printf("Sorry, %d is wrong, My number is less than that.\n", guess);
		}

	}
	printf("\nYou have had five tries and failed. The number was %d\n", randomNumber);

	return 0;
}