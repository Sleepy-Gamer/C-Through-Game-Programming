//Create a story based on user input.

#include <iostream>
#include <string>

using namespace std;

string askText(string prompt);
int askNumber(string prompt);
void tellStory(string name, string noun, int number, string bodyPart, string verb);

int main()
{
	cout << "Welcome to Mad Lib" << endl << endl;
	cout << "Answer the following questions to help create a new story!" << endl;

	string name = askText("Please enter a name: ");
	string noun = askText("Please enter a plural noun: ");
	int number = askNumber("Please enter a number: ");
	string bodyPart = askText("Please enter a body part: ");
	string verb = askText("Please enter a verb: ");

	tellStory(name, noun, number, bodyPart, verb);

	system("pause");
	return 0;
}

string askText(string prompt)
{
	string text;
	cout << prompt;
	cin >> text;
	return text;
}

int askNumber(string prompt)
{
	int num;
	cout << prompt;
	cin >> num;
	return num;

}
void tellStory(string name, string noun, int number, string bodyPart, string verb)
{
	cout << endl << "Here's your story:" << endl;
	cout << "The famous explorer ";
	cout << name;
	cout << " had nearly given up a life-long quest to find " << endl;
	cout << "The lost city of ";
	cout << noun;
	cout << " when one day, the ";
	cout << noun;
	cout << " found the explorer." << endl;
	cout << "Surrounded by ";
	cout << number;
	cout << " " << noun;
	cout << ", a tear came to ";
	cout << name << "'s ";
	cout << bodyPart << "." << endl;
	cout << "After all this time, the quest was finally over.";
	cout << " And then, the ";
	cout << noun << endl;
	cout << "promptly devoured ";
	cout << name << ". ";
	cout << "The moral of the story? Be careful what you ";
	cout << verb;
	cout << " for.";

}
