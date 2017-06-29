/*
Pseudocode:
Create a group of words.
Pick a random word from the group as the secret word.

While player hasn't made too many wrong guesses and hasn't guessed the secret word
	Tell player how many inncorrect guesses they have left.
	Show player the letters he or she has guessed. 
	Show player how much of the secret word they have guessed.
	Get player's next guess

	While player has entered a letter they have already guessed
		Get player's guess.
	Add the new guess to the group of used letters

	If the guess is the secret word
		Tell the player the guess is correct
		Update the word so far with the new letter
	Otherwise
		Tell the player the guess is inncorrect
		Increament the number of incorrect guesses the player has made.
	
	If the player has made too many incorrect guesses 
		Tell the player they have been hanged
	Otherwise
		Congratulate the player on guessing the secret word.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype> //functions that convert characters to uppercase. 

using namespace std;

int main()
{
	//Setup the game.

	const int MAX_WRONG_GUESSES = 8; //Max amount of wrong guesses allowed.

	vector<string> words; //collection of guessable words
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(static_cast<unsigned int> (time(0)));
	random_shuffle(words.begin(), words.end()); 
	const string THE_WORD = words[0];        //Word to guess
	int wrong = 0;                          //incorrect guess counter.
	string soFar(THE_WORD.size(), '-');    //word guessed so far.
	string used = "";                     //Letters already guessed.

	cout << "Welcome to Hangman." << endl; 

	//Main loop of game.
	while ((wrong < MAX_WRONG_GUESSES) && (soFar != THE_WORD))
	{
		cout << "You have " << (MAX_WRONG_GUESSES - wrong);
		cout << " inncorrect guesses left." << endl;
		cout << "You have used the following letters: " << endl;	
		cout << used << endl;
		cout << "So far the word is: " << endl << soFar << endl;

		char guess; //Player guess
		cout << "\nPlease enter your guess:     ";
		cin >> guess;
		guess = toupper(guess); //This makes the secret word in uppercase as the word is in uppercase.

		while (used.find(guess) != string::npos)
		{
			cout << "You've already guessed " << guess << endl;
			cout << "Please enter your guessL     ";
			cin >> guess;
			guess = toupper(guess);
		}

		used += guess; //adds the guessed letters to the used letters string.

		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "That's right! " << guess << " is in the word." << endl;

			//Update so far to include the newly guessed letter.
			for (int i = 0; i < THE_WORD.length(); i++)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry, " << guess << " isn't in the word." << endl;
			wrong++;
		}
	}

	//Finishing the game.
	if (wrong == MAX_WRONG_GUESSES)
	{
		cout << endl << "You've been hung!" << endl;
	}
	else
	{
		cout << "You guessed it!" << endl;
	}

	cout << "The word was " << THE_WORD << endl;


	system("pause");
	return 0;
}
