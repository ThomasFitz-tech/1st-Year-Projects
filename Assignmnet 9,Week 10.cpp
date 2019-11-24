// Week 10 Assignmnet 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "stdlib.h"
#include "conio.h"
#include <windows.h>

// function to wait 't' seconds
void wait(long t);
// function to use the Beep function in Windows
void BeepSound(int num);
// function to play a tune when you spin 3 of a kind
void WinnerSound();

void main()
{
	int nums[4];
	char c;
	int numhearts, numspades, numdiamonds, numclubs;

	// call this function if there are 3 of any suit out of the 4 drawn
	WinnerSound();
	



	// use this function to wait a second between each character appearing
	wait(1);


	// use _getch (or getch depending on your compiler) to get a character from the std input without echoing to screen
	printf("Welcome to a kinda fruit machine - press space bar to spin\n");
	c = _getch();

	// if not a space then leave
	if (c != ' ')
	{
		puts("I said SPACE BAR!!!");
		exit;
	}

	// main body of the program
	// reset counters for the suit characters
	while (c == ' ')
	{
		numhearts = 0;
		numspades = 0;
		numdiamonds = 0;
		numclubs = 0;
		int num = 0;

		// generate 4 random numbers between 3 and 6
		for (int i = 0; i < 4; i++)
		{
			// CODE HERE
			num = rand() % (6 - 3 + 1) + 3;
			if (num ==3)
			{
				numhearts++;
			}
			else if (num ==4)
			{
				numspades++;
			}
			else if (num ==5)
			{
				numdiamonds++;
			}
			else if (num ==6)
			{
				numclubs++;
			}
				// increment counters 
				// CODE HERE
				
		

			// output the sound for the character
			// CODE HERE
			BeepSound(num);
	
			// output the character
			// CODE HERE
			printf("%c", num);
			
			// wait a second before generating next character
			// CODE HERE
			wait(1);
			
		}

		// if there are 3 of any suit in the 4 characters, then it's a winner
		if(numhearts>=3||numspades>=3||numdiamonds>=3||numclubs>=3) // CODE HERE
		{
			printf("Congratulations - you're a winner!!\n");
			WinnerSound();
			// wait 2 seconds before continuing
			wait(2);
		}
		printf("\n");
		c = _getch();
	}



}

// function to play a different sound for each of the 4 characters
void BeepSound(int num)
{
	double note = 240;
	int duration = 300;

	Beep(note * num, duration);

}

// function to play winning sound - needs work!
void WinnerSound()
{
	Beep(1993.45, 500);
	Beep(757.34, 400);


}

// function to wait for 't' seconds
void wait(long t)
{
	long diff = 0;
	long now = time(NULL);

	long then = time(NULL);
	while (diff < t)
	{
		then = time(NULL);
		diff = then - now;
	}
}


