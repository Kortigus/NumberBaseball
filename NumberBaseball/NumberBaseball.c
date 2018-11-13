#include <stdio.h>
#include <stdlib.h>

#define LINESIZE (1024)

void Init(int *number1, int *number2, int *number3)
{
	int test1;
	int test2;
	int test3;
	while (1)
	{
		test1 = rand() % 10;
		test2 = rand() % 10;
		test3 = rand() % 10;

		if (test1 == test2 || test1 == test3 || test2 == test3)
		{
			continue;
		}

		*number1 = test1;
		*number2 = test2;
		*number3 = test3;
		break;
	}
	printf("Welcome to Number Baseball!\n");
}

void Update(int *number1, int *number2, int *number3) {
	int guess1;
	int guess2;
	int guess3;
	while (1) {
		char line[LINESIZE];
		int numbersEntered = 0;
		guess1 = -1;
		guess2 = -1;
		guess3 = -1;
		printf("Choose 3 numbers:\n");
		if (!fgets(line, LINESIZE, stdin)) {
			clearerr(stdin);
			printf("\n");
			continue;
		}
		if ((numbersEntered = sscanf(line, "%d %d %d",
			&guess1, &guess2, &guess3)) == 3)
		{
			int correctCount = 0;

			if (guess1 == *number1)
			{
				printf("Strike! ");
				correctCount++;
			}
			else if (guess1 == *number2 || guess1 == *number3)
			{
				printf("Out! ");
			}
			else
			{
				printf("Ball! ");
			}

			if (guess2 == *number2)
			{
				printf("Strike! ");
				correctCount++;
			}
			else if (guess2 == *number1 || guess2 == *number3)
			{
				printf("Out! ");
			}
			else
			{
				printf("Ball! ");
			}

			if (guess3 == *number3)
			{
				printf("Strike!\n");
				correctCount++;
			}
			else if (guess3 == *number1 || guess3 == *number2)
			{
				printf("Out!\n");
			}
			else
			{
				printf("Ball!\n");
			}

			if (correctCount == 3) {
				printf("You win!\n");
				exit(1);
			}
			else
			{
				printf("Try again!\n");
			}
			clearerr(stdin);
		}
		else if (numbersEntered > 3 || numbersEntered < 3)
		{
			printf("Invalid amount of numbers. Please choose 3 numbers.\n");
			continue;
		}
	}
}

/*
void Render() {

}
*/

/*
void Release() {

}
*/

int main(void)
{
	int random1;
	int random2;
	int random3;
	int *n1 = &random1;
	int *n2 = &random2;
	int *n3 = &random3;

	Init(n1, n2, n3);
	while (1)
	{
		Update(n1, n2, n3);
		/* Render(); */
	}
	/* Release(); */

	return 0;
}