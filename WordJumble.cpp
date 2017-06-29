//Chapter 3


//Word Jumble
//The classic word jumble game where the player can ask for a hint.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel you're banging your head on something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Goign slowly isn't it?"},
		{"persistent", "Keep at it."},
		{"jumble", "it's what the game is all about."}

	};

	srand(static_cast<unsigned int>(time(0)));

	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD]; //Word to guess
	string theHint = WORDS[choice][HINT]; //hint for the word being guessed.

	string jumble = theWord; //jumbled version of the word.
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		//This is cool.
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	//Welcome player
	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";

	//Present jumbled word and ask for guess.
	cout << "The jumble is: " << jumble;
	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "Sorry, that's not it.";
		}

		cout << "\n\nYour guess: ";
		cin >> guess;
	}

	if (guess == theWord)
	{ 
		cout << "\nThat's it! You guessed it!\n"; 
	}


	cout << "\nThanks for playing.\n";
	



	system("pause");
	return 0;
}
