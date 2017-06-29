
//Lost fortune
//A personalized adventure

#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int GOLD_PIECES = 900;
	int adventurers, killed, survivors;
	string leader;

	//Get information from the player
	cout << "Welcome to Lost Fortune." << endl << endl;
	cout << "Please enter the following for your personalised adventure." << endl;

	cout << "Enter a number: " << endl;
	cin >> adventurers;

	cout << "Enter a number smaller than the first: " << endl;
	cin >> killed;

	survivors = adventurers - killed;

	cout << "Enter your last name: " << endl;
	cin >> leader;

	//Tell the story

	cout << endl;
	cout << "A brave group of " << adventurers << " set out on a quest ";
	cout << "in search of the lost treasure of the Ancient Dwarves." << endl;
	cout << "The group was lead by the legendary rogue, " << leader << endl;
	cout << endl;
	cout << "Along the way, a band of maurauding ogres ambushed the party. ";
	cout << "All fought bravely under the command of " << leader << "," << endl;
	cout << "and the ogres were deafeated, but at a cost.";
	cout << " Of the adventures, " << killed << " were vanquised, ";
	cout << "leaving just " << survivors << " in the group." << endl;
	cout << endl;
	cout << "The party was about to give up all hope.";
	cout << " But while laying the deceased to rest, ";
	cout << "they stumled upon the buried fortune." << endl;
	cout << "So the adventures split " << GOLD_PIECES << " gold pieces.";
	cout << leader << " held onto the extra " << (GOLD_PIECES % survivors);
	cout << " piecies to keep things fair of course" << endl;


	system("pause");
	return 0;
}
