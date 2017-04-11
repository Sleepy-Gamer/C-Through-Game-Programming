//Chapter two
//End of chapter game

//Guess my number
//The classic number guessing game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0))); //Seed the random number generator

	int secretNumber = rand() % 100 + 1; //random number between 1 and 100.
	int tries = 0;
	int guess;

	cout << "\tWelcome to Guess My Number" << endl << endl;

	do
	{
		cout << "Enter a guess: ";
		cin >> guess;
		++tries;

		if (guess > secretNumber)
		{
			cout << "Too high!" << endl << endl;
		}

		else if (guess < secretNumber)
		{
			cout << "Too low!" << endl << endl;
		}

		else
		{
			cout << "\nThat's it! You got it in " << tries << " guesses!" << endl;
		}
	} while (guess != secretNumber);




	system("pause");
	return 0;
}
