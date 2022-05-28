#include<iostream>
using namespace std;
void printboard(int arr[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == 0)
				cout << "_ ";
			else if (arr[i][j] == 1)
				cout << "O ";
			else
				cout << "X ";
		}
		cout << endl;
	}
}
bool checkwinner(int arr[][3], int r, int &who)
{
	for (int i = 0; i < 3; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && arr[i][0] != 0)
		{
			who = arr[i][0];
			return true;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && arr[0][i] != 0)
		{
			who = arr[0][i];
			return true;
		}
	}
	if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] != 0)
	{
		who = arr[0][0];
		return true;
	}
	if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[0][2] != 0)
	{
		who = arr[0][2];
		return true;
	}
	return false;
}
void calcposition(int board[][3], int opp, int &r, int &c)
{
	int who;
	bool winner=false;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
		if (board[i][j] == 0)
		{
			r = i;
			c = j;
			board[i][j] = 1;
			winner = checkwinner(board, 3, who);
			board[i][j] = 0;
			if (winner == true)
				return;
		}
		if (board[i][j] == 0)
		{
			r = i;
			c = j;
			board[i][j] = 2;
			winner = checkwinner(board, 3, who);
			board[i][j] = 0;
			if (winner == true)
				return;
		}
		}
	if (board[1][1] == 0)
	{
		r = 1;
		c = 1;
	}

}	//end of function
int main()
{
	int board[3][3] = { 0 },player=1,row,col,who;
	bool winner = false;
	printboard(board);
	for (int i = 0; i < 9 && winner == false; i++)
	{
		cout << "Turn of player: " << player;
		if (player == 1)
		{
			cout << "\n Enter coordinates " << endl;
			calcposition(board, 2, row, col);	//cin>>row>>col;(by computer)
			while (board[row][col] != 0)
			{
				cout << "\n This place is already taken, Enter new coordinates " << endl;
				cin >> row >> col;
			}
			board[row][col] = 1;
			player = 2;
		}
		else
		{
			cout << "\n Enter coordinates " << endl;
			cin >> row >> col;
			while (board[row][col] != 0)
			{
				cout << "\n This place is already taken, Enter new coordinates " << endl;
				cin >> row >> col;
			}
			board[row][col] = 2;
			player = 1;
		}
		printboard(board);
		winner = checkwinner(board, 3, who);
		if (winner == true)
			cout << "Winner is player " <<who <<endl;
	}
	system("pause");
	return 0;
}