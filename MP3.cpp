// MP3.cpp - Grant Pfeifer - November 07, 2016
// A simple game of tic tac toe, renamed as Tic Tac D'Oh

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Gets player input for location
int getPlayerInput(string playerName);

// Returns a false if an illegal move is made
bool isLegalMove(int location, vector<char> board);

// Places the current players mark on the board
void placeMarkOnBoard(char playerMark, int location, vector<char>& board);

// Initializes the board before each game
void clearBoard(vector<char>& board);

// Determines whether a person has won or not
bool hasThreeInRow(char playerMark, vector<char> board);

// Displays the current board
void displayBoard(vector<char> board);

// Determines if a tie has occured
bool hasTieOccurred(vector<char> board);

// Constant for the game board size
int const BOARD_SIZE = 9;

int main(void) {
	// Initializing strings for players names
	string player1;
	string player2;
	string currentPlayer; // Temporary holder for the current player

	// int to count even and odd games
	int gameCount = 0;

	// Char input for the option to play again
	char playAgain;

	// Char of the player (either 'X' or 'O')
	char playerMark;

	cout << "Tic Tac D'Oh!\n";
	cout << "Player 1 (X), Enter your name: ";
	getline(cin, player1);	// Gets first players name
	cout << "\nPlayer 2 (O), Enter your name: ";
	getline(cin, player2);	// Gets second players name
	
	// Declares the gameboard
	vector<char> gameBoard(BOARD_SIZE);
	
	// Initializes as the first player being player one and initializes scores
	currentPlayer = player1;
	int tie = 0;
	int p1score = 0;
	int p2score = 0;

	do {

		// Clear the game board
		clearBoard(gameBoard);

		do {
			int location;	// Location on the board
			displayBoard(gameBoard);	// Displays board

			// If the player is player1, their mark is 'X' else it is 'O'
			if (currentPlayer == player1)
				playerMark = 'X';
			else
				playerMark = 'O';
			location = getPlayerInput(currentPlayer);

			// Check to see if it is a legal move
			while (!isLegalMove(location, gameBoard)) {
				cout << "Please make a legal move, try again: ";
				cin >> location;
			}

			// If it is a legal move, it will put the mark on the board
			placeMarkOnBoard(playerMark, location, gameBoard);

			// See if the player has won
			if (hasThreeInRow(playerMark, gameBoard)) {
				displayBoard(gameBoard);
				cout << endl << currentPlayer << " wins!\n";
				if (currentPlayer == player1)
					p1score++;
				else
					p2score++;
				gameCount++;
				break;
			}

			// See if a tie has occured
			if (hasTieOccurred(gameBoard)) {
				displayBoard(gameBoard);
				cout << "Tie!\n";
				gameCount++;
				tie++;
				break;
			}

			// Switch Players
			if (currentPlayer == player1)
				currentPlayer = player2;
			else
				currentPlayer = player1;
		} while (true); // Continue loop until there is a winner or break

		// Display score and See if the player wants to play again
		cout << player1 << "'s score: " << p1score << endl;
		cout << player2 << "'s score: " << p2score << endl;
		cout << "Ties: " << tie << endl;
		cout << "Play again? ('Y' for yes, 'N' for no): ";
		cin >> playAgain;
		cout << endl;
		if (gameCount % 2 == 1)
			currentPlayer = player2;
		else
			currentPlayer = player1;
	} while (playAgain == 'Y' || playAgain == 'y');
}


// getPlayerInput:	Get the number of the spot where the player
//						wants to play their mark
// Parameters:		The player's name
// Side effects:	None
// Returns:			Int of the spot where the player wants to play
//						their mark
int getPlayerInput(string playerName)
{
	int location;
	
	cout << endl << playerName << ", Push the number of the location you would like to place your mark: ";

	// Get the users requested location
	cin >> location;
	cout << endl;
	return(location);
}

// isLegalMove: Determines if an illegal move is made
// Parameters:	location -	the users location they chose
//				board	 -	The gameboard
// Side effects:none
// Returns:		false if an illegal move is made, true if legal
bool isLegalMove(int location, vector<char> board)
{
	if (location < 1 || location > 9)
		return false;
	if (board[(location - 1)] == 'X' || board[(location - 1)] == 'O')
		return false;
	return true;
}

// placeMarkOnBoard:	Puts the mark on the tick-tac-D'oh board
// Parameters:			playerMark - the marker of the current player
//						location   - where the user wants to place their mark
//						board	   - a reference to the gameboard
// Side effects:		Replaces the location number with an 'X' or 'O'
// Returns:				none
void placeMarkOnBoard(char playerMark, int location, vector<char>& board)
{
	board[location - 1] = playerMark;
}

// clearBoard:		Clears the board for a new game
// Parameters:		board - Current game board
// Side effects:	Removes all 'X' and 'O' from the board
// Returns:			none
void clearBoard(vector<char>& board)
{
		board[0] = '1'; board[1] = '2'; board[2] = '3';
		board[3] = '4'; board[4] = '5'; board[5] = '6';
		board[6] = '7'; board[7] = '8'; board[8] = '9';
}

// hasThreeInRow:	Determines whether the game has been won or not
// Parameters:		playerMark	-  the mark of the current player
//					board		-  the current game board
// Side effects:	none
// Returns:			true if the player has won, false if not
bool hasThreeInRow(char playerMark, vector<char> board)
{
	if (board[6] == playerMark && board[7] == playerMark && board[8] == playerMark)
		return true;
	if (board[3] == playerMark && board[4] == playerMark && board[5] == playerMark)
		return true;
	if (board[0] == playerMark && board[1] == playerMark && board[2] == playerMark)
		return true;
	if (board[6] == playerMark && board[4] == playerMark && board[2] == playerMark)
		return true;
	if (board[8] == playerMark && board[4] == playerMark && board[0] == playerMark)
		return true;
	if (board[6] == playerMark && board[3] == playerMark && board[0] == playerMark)
		return true;
	if (board[7] == playerMark && board[4] == playerMark && board[1] == playerMark)
		return true;
	if (board[8] == playerMark && board[5] == playerMark && board[2] == playerMark)
		return true;
	return false;
}

// displayBoard:	displays the current board
// Parameters:		board - the current game board
// Returns:			none
void displayBoard(vector<char> board)
{
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << "---+---+---\n";
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "---+---+---\n";
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
}

// hasTieOccurred:	Determines whether the game has been tied
// Parameters:		board  -  the current game board
// Side effects:	none
// Returns:			true if there is a tie, false if not
bool hasTieOccurred(vector<char> board)
{
	if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' && board[5] != '6' && board[6] != '7'
		&& board[7] != '8' && board[8] != '9')
		return true;
	return false;
}
