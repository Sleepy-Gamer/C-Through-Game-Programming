/* 
Critter caretaker game
Look after yoru critter and keep it happy. 
Feed it and listen to it to see how it is feeling.
*/

/* 
Planning for the game: 
Critter class:
m_hunger and m_boredom. Private data classes.
GetMood()
Talk() public.
Eat() public.
Play() public.
PassTime() private, will only be called by the three above.

Psuedocode

Create a critter
While the player doesn't want to quit the game
	Present a menu of choices to the player
	If the player wants to listen to the critter
		Make the critter talk
	If the player wants to feed the critter
		Make the critter eat.
	If the player wants to play with the critter
		Make the critter play.
*/

#include <iostream>

using namespace std;

class Critter
{
public: 
	Critter(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);

private:
	//private member functions that represents the respective values.
	int m_Hunger;
	int m_Boredom;

	int GetMood() const;
	void PassTime(int time = 1);
};

//Class constructor, takes two arguments, hunger and boredom. Each has a default value prespecified to 0.
Critter::Critter(int hunger, int boredom) :
	m_Hunger(hunger),
	m_Boredom(boredom)
{}

inline int Critter::GetMood() const
{
	return (m_Hunger + m_Boredom);
	//The critter's mood is a sum of these two values, so as they get higher, the mood will get worse. 
	//it is a constant so that it cannot change the data variables.
	//And it is private so it can only be called by another data function in the class. 
}

void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;

	//This function is called at the end of every member function where the critter does something to simulate the passing of time. 
	//It is private because it should only be called by other functions of the class. 
	//You can either set the time that has passed or allow it to use it's default value of 1.
}

void Critter::Talk()
{
	//The talk function will get the critter's mood
	//This can be happy, okay, frustrated or mad. 
	//Talk calls GetMood() and based on the return value will show a message to tell the user of the critter's mood. 
	//It will also call PassTime to pass the time. 

	cout << "I'm a critter and I feel ";

	int mood = GetMood();
	if (mood > 15)
	{
		cout << "mad." << endl;
	}
	else if (mood > 10)
	{
		cout << "frustrated." << endl;
	}
	else if (mood > 5)
	{
		cout << "okay." << endl;
	}
	else
	{
		cout << "happy." << endl;
	}

	PassTime();
}

void Critter::Eat(int food)
{
	cout << "Brruppp." << endl;
	m_Hunger -= food;

	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}

	PassTime();
}

void Critter::Play(int fun)
{
	cout << "Wheee!" << endl;

	m_Boredom -= fun;

	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}

	PassTime();
}

int main()
{
	Critter crit;
	crit.Talk();

	int choice;

	do
	{
		cout << endl << "Critter Caretaker" << endl << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - Listen to your critter." << endl;
		cout << "2 - Feed your critter." << endl;
		cout << "3 - Play with your critter." << endl;

		cout << "Choice: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "Good Bye" << endl;
			break;
		case 1:
			crit.Talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		default:
			cout << endl << "Sorry, but " << choice << " Isn't a valid choice." << endl;
		}
	} while (choice != 0);

	system("pause");
	return 0;
}
