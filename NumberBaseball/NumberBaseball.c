#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINESIZE (1024)

void Init(int* number1, int* number2, int* number3)
{
	int test1;
	int test2;
	int test3;
	time_t t;
	srand((unsigned) &t);

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
}

void Update(int* number1, int* number2, int* number3, int* guess1, int* guess2, int* guess3, int* entry)
{
	while (*entry == 1)
	{
		char line[LINESIZE];
		int numbersEntered = 0;
		*guess1 = -1;
		*guess2 = -1;
		*guess3 = -1;

		if (!fgets(line, LINESIZE, stdin))
		{
			clearerr(stdin);
			printf("\n");
			exit(1);
		}

		if ((numbersEntered = sscanf_s(line, "%d %d %d",
			guess1, guess2, guess3)) == 3)
		{
			return;
		}
		else
		{
			*entry = -1;
			return;
		}
	}
}

int Render(int* number1, int* number2, int* number3, int* guess1, int* guess2, int* guess3, int* entry)
{
	if (*entry == 0)
	{
		printf("Welcome to Number Baseball!\n");
		printf("Choose 3 numbers:\n");
		*entry = 1;
	}
	else if (*entry == -1)
	{
		printf("Invalid amount of numbers. Please choose 3 numbers.\n");
		*entry = 1;
	}
	else
	{
		int correctCount = 0;
		int* guess[] = {guess1, guess2, guess3};
		int* number[] = {number1, number2, number3, number1, number2};
		size_t i;

		for (i = 0; i < 3; i++)
		{
			if (*guess[i] == *number[i])
			{
				printf("Strike! ");
				correctCount++;
			}
			else if (*guess[i] == *number[0] || *guess[i] == *number[1] || *guess[i] == *number[2])
			{
				printf("Out! ");
			}
			else
			{
				printf("Ball! ");
			}
		}

		if (correctCount == 3)
		{
			printf("You win!\n");
			return 1;
		}
		else
		{
			printf("Try again!\n");
		}
	}
	return 0;
}

void Release()
{

}

int main(void)
{
	int random1;
	int random2;
	int random3;
	int guess1;
	int guess2;
	int guess3;
	int endGame = 0;
	int entry = 0;

	Init(&random1, &random2, &random3);
	while (endGame == 0)
	{
		Update(&random1, &random2, &random3, &guess1, &guess2, &guess3, &entry);
		endGame = Render(&random1, &random2, &random3, &guess1, &guess2, &guess3, &entry);
	}
	Release();

	return 0;
}