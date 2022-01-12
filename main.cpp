#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printBoard(vector<vector<char>> board);
bool validChoice(vector<vector<char>> board, string choice);
int getCoord(string choice);
int checkWin(vector<vector<char>> board);

int main() {
	vector<vector<char>> board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

	for (int turn = 1; turn < 10; turn++){
		cout << "\033[2J\033[0;0H";
		printBoard(board);
		if (checkWin(board) == 1){
			cout << "X wins!";
			break;
		} else if (checkWin(board) == 2){
			cout << "O wins!";
			break;
		} else if (checkWin(board) == 3 && turn == 9){
			cout << "Tie, nobody wins!";
			break;
		}
		if (turn % 2 == 1){
			cout << "X's turn" << endl;
		} else {
			cout << "O's turn" << endl;
		}
		string choice;
		cout << "Enter coord (Ex: a1): ";
		cin >> choice;
		while (!validChoice(board, choice)){
			cout << "Error: Invalid coordinate. Please try again: ";
			cin >> choice;
		}
		int y = getCoord(choice) / 10 - 1;
		int x = getCoord(choice) % 10 - 1;
		if (turn % 2 == 1){
			board[y][x] = 'X';
		} else {
			board[y][x] = 'O';
		}
	}
}

void printBoard(vector<vector<char>> board){
	cout << "========================" << endl;
	cout << "    1       2       3" << endl;
	cout << "        |       |" << endl;
	cout << "a   " << board[0][0] << "   |   " << board[0][1] << "   |   " << board[0][2] << endl;
	cout << "        |       |" << endl;
	cout << " -------|-------|-------" << endl;
	cout << "        |       |" << endl;
	cout << "b   " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << endl;
	cout << "        |       |" << endl;
	cout << " -------|-------|-------" << endl;
	cout << "        |       |" << endl;
	cout << "c   " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << endl;
	cout << "        |       |" << endl;
	cout << "========================" << endl;
}

bool validChoice(vector<vector<char>> board, string choice){
	if (choice.length() != 2){
		return false;
	}
	if (choice[0] != 'a' && choice[0] != 'b' && choice[0] != 'c'){
		return false;
	}
	if (choice[1] != '1' && choice[1] != '2' && choice[1] != '3'){
		return false;
	}
	int y = getCoord(choice) / 10 - 1;
	int x = getCoord(choice) % 10 - 1;
	if (board[y][x] == ' '){
		return true;
	}
	return false;
}

int getCoord(string choice){
	int p1, p2;
	if (choice[0] == 'a'){
		p1 = 1;
	} else if (choice[0] == 'b'){
		p1 = 2;
	} else {
		p1 = 3;
	}

	if (choice[1] == '1'){
		p2 = 1;
	} else if (choice[1] == '2'){
		p2 = 2;
	} else {
		p2 = 3;
	}

	return (p1 * 10) + p2;
}

int checkWin(vector<vector<char>> board){
	for (int y = 0; y < 3; y++){
		int nX = 0;
		int nO = 0;
		for (int x = 0; x < 3; x++){
			if (board[y][x] == 'X'){
				nX++;
			} else if (board[y][x] == 'O'){
				nO++;
			}
		}
		if (nX == 3){
			return 1;
		} else if (nO == 3){
			return 2;
		}
	}

	for (int x = 0; x < 3; x++){
		int nX = 0;
		int nO = 0;
		for (int y = 0; y < 3; y++){
			if (board[y][x] == 'X'){
				nX++;
			} else if (board[y][x] == 'O'){
				nO++;
			}
		}
		if (nX == 3){
			return 1;
		} else if (nO == 3){
			return 2;
		}
	}
	if (board[1][1] != ' '){
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
			if (board[1][1] == 'X'){
				return 1;
			} else {
				return 2;
			}
		}
		if (board[2][0] == board[1][1] && board[1][1] == board[0][2]){
			if (board[1][1] == 'X'){
				return 1;
			} else {
				return 2;
			}
		}
	}
	return 3;
}
