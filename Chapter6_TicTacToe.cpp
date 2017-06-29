//Pseudocode
/*
Create an empty tic tac toe board.
Display the game instructions
Determine who goes first. (Player or AI)
Display the game board
WHILE no one has won and it's not a tie
	If it's the player's turn
		get the move.
		update the board with the move. 
	otherwise
		Calculate the ai's moves
		update the board with the move
	Display the board
	Switch turns
Congratulate the winner or inform players of a tie
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

//function prototypes
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(const vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

//Main Function
int main()
{
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);

	instructions();
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;
	displayBoard(board);

	while (winner(board) == NO_ONE)
	{
		if (turn == human)
		{
			move = humanMove(board, human);
			board[move] = human;
		}

		else
		{
			move = computerMove(board, computer);
			board[move] = computer;
		}

		displayBoard(board);
		turn = opponent(turn);
	}

	announceWinner(winner(board), computer, human);

	system("pause");
	return 0;
}

void instructions()
{
	cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe." << endl;
	cout << "--where human brain is pit against silicon processor." << endl << endl;
	
	cout << "Make your move known by entering a number, 0-8." << endl;
	cout << "The number corresponds to the desired board postition as illustrated." << endl;

	cout << "    0 | 1 | 2\n";
	cout << "    3 | 4 | 5\n";
	cout << "    6 | 7 | 8\n";
	cout << endl;

	cout << "Prepare yourself human. The battle is about the begin." << endl << endl;
}

char askYesNo(string question)
{
	char response;
	do
	{
		cout << question << " (y/n): ";
		cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}

int askNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;
	} while (number > high || number < low);

	return number;
}

char humanPiece()
{
	char go_first = askYesNo("Do you require the first move?");
	if (go_first =='y')
	{
		cout << endl << "Then take the fist move. You will need it." << endl;
		return X;
	}
	else
	{
		cout << endl << "Your bravery will be your undoing....I will go first" << endl;
		return O;
	}
}

char opponent(char piece)
{
	if (piece == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}

void displayBoard(const vector<char>& board)
{
	cout << "\n\t" << "  " <<  board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t " << " ----------";
	cout << "\n\t" << "  " <<  board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t " << " ----------";
	cout << "\n\t" << "  " << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n\n";
}

char winner(const vector<char>& board)
{
	//all the possible winning rows
	const int WINNING_ROWS[8][3] = 
	{ 
	{0, 1, 2},
	{ 3, 4, 5 },
	{ 6, 7, 8 },
	{ 0, 3, 6 },
	{ 1, 4, 7 },
	{ 2, 5, 8 },
	{ 0, 4, 8 },
	{ 2, 4, 6 } 
	};

	const int TOTAL_ROWS = 8;

	//if any winning row has three values that are the same (and not EMPTY),
	//then we have a winner
	for (int row = 0; row < TOTAL_ROWS; ++row)
	{
		if ( (board[WINNING_ROWS[row][0]] != EMPTY) && 
			(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
			(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
		{
			return board[WINNING_ROWS[row][0]];
			}
	}

	//since nobody has won, check for a tie. (no empty squares left)
	if (count(board.begin(), board.end(), EMPTY) == 0)
	{
		return TIE;
	}


	//Since no one has won and it isn't a tie, the game is still going.
	return NO_ONE;
									
}

inline bool isLegal(const vector<char>& board, int move)
{
	return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human)
{
	int move = askNumber("Where will you move?", (board.size() - 1));

	while (!isLegal(board, move))
	{
		cout << "\nThat square is already occupied, foolish human." << endl;
		move = askNumber("Where will you move?", (board.size()));
	}
	cout << "Fine...." << endl;

	return move;
}

int computerMove(vector<char> board, char computer)
{
	//Code for AI.

	unsigned int move = 0;
	bool found = false;
	//If the computer can win on this move. Take it.
	while (!found && move < board.size())
	{
		if (isLegal(board, move))
		{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}

		if (!found)
		{
			++move;
		}
	}

	//If the human can win next move, block it.
	if (!found)
	{
		move = 0;
		char human = opponent(computer);

		while (!found && move < board.size())
		{
			if (isLegal(board, move))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}

			if (!found)
			{
				++move;
			}
		}
	}
	//Take the best remaining square. Ranking from centre, corners and the rest.

	if (!found)
	{
		move = 0;
		unsigned int i = 0;

		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
		//pick the best open square.
		while (!found && i < board.size())
		{
			move = BEST_MOVES[i];
			if (isLegal(board, move))
			{
				found = true;
			}

			++i;
		}
	}

	cout << "I shall take square number " << move << endl;
	return move;
}

void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
	{
		cout << winner << "'s won!" << endl;
		cout << "As I predicted, human, I am triumphant once more!" << endl;
		cout << "Proof that computers are superior to humans in all regards." << endl;
	}
	
	else if (winner == human)
	{
		cout << winner << "'s won!" << endl;
		cout << "No, no! It cannot be! Somehow you tricked me human!" << endl;
		cout << "But never again! I, the computer, so swear it!" << endl;
	}

	else
	{
		cout << "It is a tie!" << endl;
		cout << "You were mostly lucky, human, and somehow managed to tie me." << endl;
		cout << "Celebrate...for this is the best you will ever achieve." << endl;
	}
}
