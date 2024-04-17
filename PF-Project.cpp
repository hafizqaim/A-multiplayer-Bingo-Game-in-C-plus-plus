#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<ctime>
#include<fstream>
#include<windows.h>
using namespace std;
// Function PlayerBoard generates the Board for the Players
void player1board(int Temp[], int Player1Board[][5])
{
	int x;//This variable is used to store the random value temporarily
	bool b;//Bool is used to check and avoid the repetition of the Numbers in the Board
	srand(time(0));
	//1D array is used for input of random values and then the values are transfered in 2D array (for our ease)
	for (int i = 0; i < 25; i++)
	{
		do//Do-While loop is used to avoid repetition of same numbers in the Temp Array
		{
			x = 1 + (rand() % 25);
			b = true;
			for (int j = 0; j < i; j++)
			{
				if (Temp[j] == x)
				{
					b = false;
				}
			}
		} while (!b);
		Temp[i] = x;
	}
	cout << endl;
	int c = 0;
	while (c < 25)//This loop puts all the values of Temp array in The Player 1 Board
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				Player1Board[i][j] = Temp[c];
				c++;
			}
		}
	}
}
void player2board(int Player2Board[][5], int Temp[])
{
	int x;//This variable is used to store the random value temporarily
	bool b;//Bool is used to check and avoid the repetition of the Numbers in the Board
	//1D array is used for input of random values and then the values are transfered in 2D array (for our ease)
	for (int i = 0; i < 25; i++)
	{
		do//Do-While loop is used to avoid repetition of same numbers in the Temp Array
		{
			x = 1 + (rand() % 25);
			b = true;
			for (int j = 0; j < i; j++)
			{
				if (Temp[j] == x)
				{
					b = false;
				}
			}
		} while (!b);
		Temp[i] = x;
	}
	cout << endl;
	int c = 0;
	while (c < 25)//This loop puts all the values of Temp array in The Player 2 Board
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				Player2Board[i][j] = Temp[c];
				c++;
			}
		}
	}
}
void InputNames(string& player1name, string& player2name)//This Function Inputs the Names of the players
{
	cout << "  Enter Player 1 Name : ";
	cin >> player1name;
	cout << "  Enter Player 2 Name : ";
	cin >> player2name;
}
int PlayerTurn(int& Turn)//This Function Randomly Inputs the Turn of the Players
{
	int x, c = 0;
	srand(time(0));
	x = rand() % 10;
	while (c < x)
	{
		Turn = Turn + (5 * c);
		Turn = Turn % 2;
		c++;
	}
	return Turn;
}
void PrintBoard(int Player1Board[][5], bool Turn, string Player1Name)//Function Overloading is used to Print The boards of the Player
{
	cout << "  " << Player1Name << "'s Turn " << endl << endl;
	cout << setw(40) << "--------------------------------------" << endl;//This Forms the Upper Borders of the Player Board
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(3) << "|" << setw(3) << Player1Board[i][j];
			cout << " |";
		}
		cout << endl;
	}
	cout << setw(40) << "--------------------------------------" << endl;//This Forms the Lower Borders of the Player Board
}
void PrintBoard(bool Turn, int Player2Board[][5], string Player2Name)//Function Overloading is used to Print The boards of the Player
{
	cout << "  " << Player2Name << "'s Turn " << endl << endl;
	cout << setw(40) << "--------------------------------------" << endl;//This Forms the Upper Borders of the Player Board
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(3) << "|" << setw(3) << Player2Board[i][j];
			cout << " |";
		}
		cout << endl;
	}
	cout << setw(40) << "--------------------------------------" << endl;//This Forms the Lower Borders of the Player Board
}
void GameRun(int player1Board[][5], int player2Board[][5], bool Turn)//This function Inputs index from the players according to the turn and checks the Input
{
	int Input;
	cout << "  Enter the Number to make your move : ";
	cin >> Input;
	while (Input <= 0 || Input > 25)//This loop checks the Input to be in rage untill correct Input in Entered
	{
		cout << "  Wrong Input! Enter the Input again : ";
		cin >> Input;
	}
	if (Turn == 0)//This check is for the Turn of the Player
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (player1Board[i][j] == Input)//This checks the Input and change it to 0 if avaible in player 1 Board
				{
					player1Board[i][j] = 0;
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (player2Board[i][j] == Input)//This checks the Input and change it to 0 if avaible in player 2 Board
			{
				player2Board[i][j] = 0;
			}
		}
	}
	if (Turn == 1)//This check is for the Turn of the Player
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (player2Board[i][j] == Input)//This checks the Input and change it to 0 if avaible in player 2 Board
				{
					player2Board[i][j] = 0;
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (player1Board[i][j] == Input)//This checks the Input and change it to 0 if avaible in player 1 Board
			{
				player1Board[i][j] = 0;
			}
		}
	}
}
void Win(int player1Board[][5], int player2Board[][5], bool& end, string player1name, string player2name, int& P1score, int& P2score)//This function checks for the Winning conditions
{
	int diagonal_P1 = 0, diagonal_P2 = 0, Row1_P1 = 0, Row1_P2 = 0, Row2_P1 = 0, Row2_P2 = 0, Row3_P1 = 0, Row3_P2 = 0, Row4_P1 = 0, Row4_P2 = 0, Row5_P1 = 0, Row5_P2 = 0, Column1_P1 = 0, Column1_P2 = 0, Column2_P1 = 0, Column2_P2 = 0, Column3_P1 = 0, Column3_P2 = 0, Column4_P1 = 0, Column4_P2 = 0, Column5_P1 = 0, Column5_P2 = 0, Win_P1 = 0, Win_P2 = 0;
	for (int i = 0; i < 5; i++)//This loop Sums up the variables for winning coditions
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j)//For Diagonal check
			{
				if (player1Board[i][j] == 0)
				{
					diagonal_P1++;
				}
				if (player2Board[i][j] == 0)
				{
					diagonal_P2++;
				}
			}
			if (j == 0 && i < 5)//For Row 1 check
			{
				if (player1Board[i][j] == 0)
				{
					Row1_P1++;
				}
				if (player2Board[i][j] == 0)
				{
					Row1_P2++;
				}
			}
			if (j == 1 && i < 5)//For Row 2 check
			{
				if (player1Board[i][j] == 0)
				{
					Row2_P1++;
				}
				if (player2Board[i][j] == 0)
				{
					Row2_P2++;
				}
			}
			if (j == 2 && i < 5)//For Row 3 check
			{
				if (player1Board[i][j] == 0)
				{
					Row3_P1++;
				}
				if (player2Board[i][j] == 0)
				{
					Row3_P2++;
				}
			}
			if (j == 3 && i < 5)//For Row 4 check
			{
				if (player1Board[i][j] == 0)
				{
					Row4_P1++;
				}
				if (player2Board[i][j] == 0)
				{
					Row4_P2++;
				}
			}
			if (j == 4 && i < 5)//For Row 5 check
			{
				if (player1Board[i][j] == 0)
				{
					Row5_P1++;
				}
				if (player2Board[i][j] == 0)
				{
					Row5_P2++;
				}
			}
			if (i == 0 && j < 5)//For Column 1 check
			{
				if (player1Board[i][j] == 0)
				{
					Column1_P1++;
				}
				if (player2Board[i][j] == 0)
				{
					Column1_P2++;
				}
			}
			if (i == 1 && j < 5)//For Column 2 check
			{
				if (player1Board[i][j] == 0)
				{
					Column2_P1++;
				}
				if (player2Board[i][j] == 0)
				{
					Column2_P2++;
				}
			}
			if (i == 2 && j < 5)//For Column 3 check
			{
				if (player1Board[i][j] == 0)
				{
					Column3_P1++;
				}
				if (player2Board[i][j] == 0)
				{
					Column3_P1++;
				}
			}
			if (i == 3 && j < 5)//For Column 4 check
			{
				if (player1Board[i][j] == 0)
				{
					Column4_P1++;
				}
				if (player2Board[i][j] == 0)
				{
					Column4_P2++;
				}
			}
			if (i == 4 && j < 5)//For Column 5 check
			{
				if (player1Board[i][j] == 0)
				{
					Column5_P1++;
				}
				if (player2Board[i][j] == 0)
				{
					Column5_P2++;
				}
			}
		}
	}
	if (diagonal_P1 == 5)//For Diagonal check of Player 1
	{
		Win_P1++;
	}
	if (Row1_P1 == 5)//For Row 1 check of Player 1
	{
		Win_P1++;
	}
	if (Row2_P1 == 5)//For Row 2 check of Player 1
	{
		Win_P1++;
	}
	if (Row3_P1 == 5)//For Row 3 check of Player 1
	{
		Win_P1++;
	}
	if (Row4_P1 == 5)//For Row 4 check of Player 1
	{
		Win_P1++;
	}
	if (Row5_P1 == 5)//For Row 5 check of Player 1
	{
		Win_P1++;
	}
	if (Column1_P1 == 5)//For Column 1 check of Player 1
	{
		Win_P1++;
	}
	if (Column2_P1 == 5)//For Column 2 check of Player 1
	{
		Win_P1++;
	}
	if (Column3_P1 == 5)//For Column 3 check of Player 1
	{
		Win_P1++;
	}
	if (Column4_P1 == 5)//For Column 4 check of Player 1
	{
		Win_P1++;
	}
	if (Column5_P1 == 5)//For Column 5 check of Player 1
	{
		Win_P1++;
	}
	if (Win_P1 >= 5)//This checks the winning conditions for player 1
	{
		end = 1;
		P1score++;
		int c = 0;
		while (c < 5)
		{
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*" << endl;
			cout << "\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*" << endl;
			cout << "\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*    " << player1name << " WON    !*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*" << endl;
			cout << "\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*" << endl;
			cout << "\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*" << endl;
			Sleep(250);
			system("CLS");
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!" << endl;
			cout << "\t*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!" << endl;
			cout << "\t*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!     " << player1name << " WON    !*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*" << endl;
			cout << "\t*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!" << endl;
			cout << "\t*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!" << endl;
			Sleep(250);
			system("CLS");
			c++;
		}
	}
	if (diagonal_P2 == 5)//For Diagonal check of Player 2
	{
		Win_P2++;
	}
	if (Row1_P2 == 5)//For Row 1 check of Player 2
	{
		Win_P2++;
	}
	if (Row2_P2 == 5)//For Row 2 check of Player 2
	{
		Win_P2++;
	}
	if (Row3_P2 == 5)//For Row 3 check of Player 2
	{
		Win_P2++;
	}
	if (Row4_P2 == 5)//For Row 4 check of Player 2
	{
		Win_P2++;
	}
	if (Row5_P2 == 5)//For Row 5 check of Player 2
	{
		Win_P2++;
	}
	if (Column1_P2 == 5)//For Column 1 check of Player 2
	{
		Win_P2++;
	}
	if (Column2_P2 == 5)//For Column 2 check of Player 2
	{
		Win_P2++;
	}
	if (Column3_P2 == 5)//For Column 3 check of Player 2
	{
		Win_P2++;
	}
	if (Column4_P2 == 5)//For Column 4 check of Player 2
	{
		Win_P2++;
	}
	if (Column5_P2 == 5)//For Column 5 check of Player 2
	{
		Win_P2++;
	}
	if (Win_P2 >= 5)//This checks the winning conditions for player 2
	{
		P2score++;
		end = 1;
		int c = 0;
		while (c < 5)
		{
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*" << endl;
			cout << "\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!" << endl;
			cout << "\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*     " << player2name << " WON    !*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*" << endl;
			cout << "\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!" << endl;
			cout << "\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*" << endl;
			Sleep(250);
			system("CLS");
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!!*!*!*!*!*!*!*!*!*!*!*!*!*!*!" << endl;
			cout << "\t*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*" << endl;
			cout << "\t*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!    " << player2name << " WON    !*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*" << endl;
			cout << "\t*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*" << endl;
			cout << "\t*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!!*!*!*!*!*!*!*!*!*!*!*!*!*!*!" << endl;
			Sleep(250);
			system("CLS");
			c++;
		}
	}
}
void AnimationToss(int Turn)
{
	cout << setw(10) << "Player 1 Turn = 0       Player 2 Turn = 1 " << endl << endl;
	int c = 0;
	while (c < 10)
	{
		int x = 0;
		cout << "\r\t\tToss : " << x;
		Sleep(50);
		x = 1;
		cout << "\r\t\tToss : " << x;
		Sleep(50);
		x = 0;
		cout << "\r\t\tToss : " << x;
		Sleep(50);
		c++;
	}
	cout << "\r\t\tToss : " << Turn;
	Sleep(1500);
}
void AnimationLoading()
{
	int c = 0;
	while (c < 1)
	{
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(60) << "Loading.....";
		Sleep(550);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(60) << "Loading ....";
		Sleep(550);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(60) << "Loading. ...";
		Sleep(550);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(60) << "Loading.. ..";
		Sleep(550);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(60) << "Loading... .";
		Sleep(550);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(60) << "Loading.....";
		system("CLS");
		c++;
	}
}
void FileRecords(string history, int clear)//File Handling is used in this function
{
	string RECORD;
	fstream file;
	file.open("RECORD.txt", ios::app);
	file << history;
	file.close();
	fstream file1;
	file1.open("RECORD.txt", ios::in);
	while (!file1.eof())
	{
		getline(file1, RECORD);
		cout << RECORD << endl;
	}
	file1.close();
}
void FileRecords(int clear, string history)//File Handling is used in this function
{
	string Null = " ";
	fstream file;
	file.open("RECORD.txt", ios::out);
	file << Null;
	file.close();
}
void PrintBingo()//This function Prints BINGO
{
	system("CLS");//This Function Clear the screen so each player can see only their own Board
	cout << endl << endl;
	cout << "	 	     |---------|       ---      ||        |   |----------        |---------|" << endl;
	cout << "		     |          |       |       | |       |   |                  |         |" << endl;
	cout << "		     |           |      |       |  |      |   |                  |         |" << endl;
	cout << "		     |          |       |       |   |     |   |                  |         |" << endl;
	cout << "		     |---------|        |       |    |    |   |     |----|       |         |" << endl;
	cout << "		     |          |       |       |     |   |   |     |    |       |         |" << endl;
	cout << "		     |           |      |       |      |  |   |          |       |         |" << endl;
	cout << "		     |          |       |       |       | |   |          |       |         |" << endl;
	cout << "		     |---------|       ---      |        ||   |----------|       |---------|" << endl << endl << endl;
}
int main()
{
	system("color D");//system color command. XY where x is for background color and y is for text color
	srand(time(0));
	int GameID = rand(), Return, choice = 0, P1score = 0, P2score = 0, Turn = 0, clear = 2;
	int Temp[25];// Temperory 1D array (for our ease)
	int Player1Board[5][5], Player2Board[5][5];//Arrays for the Board for each Player
	bool end = 0;
	string player1name = "NULL", player2name = "NULL", history, gameid, p1score = "NULL", p2score = "NULL";
	while (choice != 4)//This loop keeps running untill 4 is pressed to end the game
	{
		PrintBingo();//This function Prints BINGO
		cout << "---------------------------------------------|  Lets Play BINGO  |------------------------------------------------------" << endl << endl;
		cout << setw(30) << "--Main Menu--" << endl << endl;
		cout << setw(43) << "-> Enter 1 to play the Game" << endl;
		cout << setw(59) << "-> Enter 2 to see the Previous Game Records" << endl;
		cout << setw(49) << "-> Enter 3 to see the Instruction" << endl;
		cout << setw(42) << "-> Enter 4 to End the Game" << endl << endl;
		cout << setw(30) << "Your choice : ";
		cin >> choice;
		while (choice >= 5 || choice <= 0)
		{
			cout << "Enter your choice again : ";
			cin >> choice;
		}
		system("CLS");//This Function Clear the screen so each player can see only their own Board
		AnimationLoading();//This function animates the Loading screen
		switch (choice)
		{
		case 1:
			end = 0, P1score = 0, P2score = 0;
			PrintBingo();//This function Prints BINGO		
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << setw(50) << "Game ID   " << GameID << endl;
			InputNames(player1name, player2name);//This Function Inputs the Names of the players
			player1board(Temp, Player1Board);
			player2board(Player2Board, Temp);
			PlayerTurn(Turn);//This function will decide the Player turn;
			AnimationToss(Turn);
			while (end != 1)
			{
				PrintBingo();//This function Prints BINGO
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << setw(50) << "Game ID   " << GameID << endl;
				if (end == 0)
				{
					while (Turn == 0)
					{

						PrintBoard(Player1Board, Turn, player1name);//This Function Prints the Board of Player 1
						GameRun(Player1Board, Player2Board, Turn);//This function Inputs index from the players according to the turn and checks the Input
						PrintBingo();//This function Prints BINGO
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
						cout << setw(50) << "Game ID   " << GameID << endl;
						Win(Player1Board, Player2Board, end, player1name, player2name, P1score, P2score);//This function checks for the Winning conditions
						Turn = 1;
						break;
					}
				}

				if (end == 0)
				{
					while (Turn == 1)
					{
						PrintBoard(Turn, Player2Board, player2name);//This Function Prints the Board of Player 2
						GameRun(Player1Board, Player2Board, Turn);//This function Inputs index from the players according to the turn and checks the Input
						PrintBingo();//This function Prints BINGO
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
						cout << setw(50) << "Game ID   " << GameID << endl;
						Win(Player1Board, Player2Board, end, player1name, player2name, P1score, P2score);//This function checks for the Winning conditions
						Turn = 0;
						break;
					}
				}
			}
			system("CLS");
			AnimationLoading();//This function animates the Loading screen
			break;
		case 2:
			clear = 2;
			PrintBingo();//This function Prints BINGO
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << setw(40) << "--File Contents--" << endl << endl;
			gameid = to_string(GameID);
			p1score = to_string(P1score);
			p2score = to_string(P2score);
			history = "->Game ID : " + gameid + " ->Player 1 Name : " + player1name + " ->Player 2 Name : " + player2name + " ->" + player1name + "'s Score : " + p1score + " ->" + player2name + "'s Score : " + p2score;
			FileRecords(history, clear);
			cout << endl << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			while (clear >= 2 || clear <= -1)
			{
				cout << setw(56) << "Enter 1 if what to clear the privious game record" << endl;
				cout << setw(55) << "Enter 0 if what to keep the privious game record" << endl;
				cout << setw(21) << "Your choice : ";
				cin >> clear;
				FileRecords(clear, history);
			}
			system("pause");
			system("CLS");
			AnimationLoading();//This function animates the Loading screen
			break;
		case 3:
			PrintBingo();//This function Prints BINGO
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << setw(40) << "--Instructions--" << endl << endl;
			cout << "	~First each player will enter their names one by one. Each will play turn by turn. \n	~Each player be displayed their own grid" << endl;
			cout << "	~Each player will enter a number from the grid to make a move as by turn. \n	~That number will be replaced by 0 on the grid of both players " << endl;
			cout << "	~The player will win whose diagonal or any border will become zero first" << endl << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			system("pause");
			system("CLS");
			AnimationLoading();//This function animates the Loading screen
			break;
		case 4:
			return 0;
		default:
			cout << "Invalid Input! " << endl;
		}
	}
	return 0;
}
