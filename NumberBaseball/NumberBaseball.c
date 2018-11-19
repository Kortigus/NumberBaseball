#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINE_SIZE (1024)

typedef struct
{
	size_t guess1;
	size_t guess2;
	size_t guess3;
} guess;

void Init(guess* player, guess* computer)
{

	size_t test1;
	size_t test2;
	size_t test3;
	player->guess1 = -1;
	player->guess2 = -1;
	player->guess3 = -1;
	srand((unsigned)time(NULL));

	while (1)
	{
		test1 = rand() % 10;
		test2 = rand() % 10;
		test3 = rand() % 10;

		if (test1 == test2 || test1 == test3 || test2 == test3)
		{
			continue;
		}

		computer->guess1 = test1;
		computer->guess2 = test2;
		computer->guess3 = test3;
		break;
	}
}

void Update(guess* player, int* entry)
{
	while (*entry == 1)
	{
		char line[LINE_SIZE];
		size_t test1 = -1;
		size_t test2 = -1;
		size_t test3 = -1;
		size_t* guess1 = &test1;
		size_t* guess2 = &test2;
		size_t* guess3 = &test3;

		if (!fgets(line, LINE_SIZE, stdin))
		{
			clearerr(stdin);
			printf("Error reading numbers please try again or restart program.\n");
			continue;
		}

		if ((sscanf_s(line, "%u %u %u", guess1, guess2, guess3)) == 3)
		{
			player->guess1 = test1;
			player->guess2 = test2;
			player->guess3 = test3;
			return;
		}

		*entry = -1;
		return;
	}
}

int Render(guess* computer, guess* player, int* entry)
{
	if (*entry == 0)
	{
		printf("Welcome to Number Baseball!\n");
		printf("Please choose 3 unique numbers from 0 to 9\n");
		*entry = 1;
	}
	else if (*entry == -1)
	{
		printf("Invalid amount of numbers.\n Please choose 3 unique numbers from 0 to 9.\n");
		*entry = 1;
	}
	else
	{
		size_t strikeCount = 0;
		size_t outCount = 0;
		size_t ballCount = 0;
		size_t* guess[] = {player->guess1, player->guess2, player->guess3};
		size_t* number[] = {computer->guess1, computer->guess2, computer->guess3, computer->guess1, computer->guess2};
		size_t i;

		for (i = 0; i < 3; i++)
		{
			if (guess[i] == number[i])
			{
				strikeCount++;
			}
			else if (guess[i] == number[0] || guess[i] == number[1] || guess[i] == number[2])
			{
				outCount++;
			}
			else
			{
				ballCount++;
			}
		}
		printf("%u %s, %u %s, %u %s\n", strikeCount, "Strike", outCount, "Ball", ballCount, "Out");

		if (strikeCount == 3)
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
	guess player;
	guess computer;
	int endGame = 0;
	int entry = 0;

	Init(&player, &computer);
	while (endGame == 0)
	{
		Update(&player, &entry);
		endGame = Render(&computer, &player, &entry);
	}
	Release();

	return 0;
}