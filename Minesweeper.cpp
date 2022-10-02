#include <iostream>
#include <stdlib.h>
#include <time.h>    

using namespace std;

void Difficulty();
void Grid_Cout();
void Grid_build();
void Print_field();
void mine_deploy(int mine_num);
void Start();
void defeat();

const int easy = 5;
const int medium = 6;
const int hard = 8;
const int impossible = 5;

int Grid[hard][hard];
char screen[hard][hard];
int mine_loc = 0;
int select_dif;
int Grid_Size;
const char* line = "__________________________________";
bool Print;
int mines;
int SafeSpot;
int Round_End;
int Round = 0;
int x = 0;
int y = 0;
int i;
int j;
int dep_mines;


void main()
{
	int SafeSpot = 0;
	system("Color 08");
	Difficulty();
	Grid_build();
}
void Difficulty() {
	dep_mines = 0;
	cout << "\n Minesweeper\nDifficulty selection:\n (1) easy\n (2) medium\n (3) hard\n (4) impossible" << endl;
	do {
		cout << "Select a difficulty to begin";
		cin >> select_dif;

		if (select_dif == 1) {
			cout << "----Easy Mode----" << endl;
		}
		else if (select_dif == 2) {
			cout << "----Medium Mode----" << endl;
		}
		else if (select_dif == 3) {
			cout << "----Hard Mode----" << endl;
		}
		else if (select_dif == 4) {
			cout << "----Impossible----" << endl;
		}
		else {
			cout << "Please try again" << endl;
		}
	} while (select_dif != 1 && select_dif != 2 && select_dif != 3 && select_dif != 4);
}
void Grid_build() {
	cout << select_dif << endl;
	for (int i = 0; i < Grid_Size; i++)
	{
		for (int j = 0; j < Grid_Size; j++)
		{
			Grid[i][j] == 0;
		}
	}

	if (select_dif == 1)
	{
		mines = 10;
		Grid_Size = easy;
		Grid[easy][easy];

		mine_deploy(mines);

	}
	else if (select_dif == 2) {
		mines = 15;
		Grid_Size = medium;
		Grid[medium][medium];

		mine_deploy(mines);
	}
	else if (select_dif == 3) {
		mines = 20;
		Grid_Size = hard;
		Grid[hard][hard];

		mine_deploy(mines);
	}
	else if (select_dif == 4) {
		mines = 24;
		Grid_Size = impossible;
		Grid[impossible][impossible];

		mine_deploy(mines);
	}
	Grid_Cout();
}


void mine_deploy(int mine_num) {
	srand(time(0));
	do
	{
		do
		{
			i = rand() % Grid_Size;
			j = rand() % Grid_Size;
		} while (Grid[i][j] != 0);
		Grid[i][j] = 9;
		dep_mines++;
	} while (dep_mines < mines);

	cout << "Mines: " << dep_mines << endl;
}

void Grid_Cout() {
	if (select_dif == 1)
	{
		Round_End = 15;
	}
	else if (select_dif == 2) {
		Round_End = 21;
	}
	else if (select_dif == 3) {
		Round_End = 44;
	}
	else if (select_dif == 4) {
		Round_End = 1;
	}
	Print = false;

	do
	{

		if (i >= 0) {
			for (int i = 0; i < Grid_Size; i++)
			{
				for (int j = 0; j < Grid_Size; j++)
				{
					if (Grid[x][y] == 9)
					{
						continue;
					}
					mine_loc = 0;
					if (Grid[x][y - 1] == 9) {
						mine_loc++;
					}
					if (Grid[x - 1][y - 1] == 1) {
						mine_loc++;
					}
					if (Grid[x + 1][y - 1] == 1) {
						mine_loc++;
					}
					if (Grid[x - 1][y] == 9) {
						mine_loc++;
					}
					if (Grid[x + 1][y] == 9) {
						mine_loc++;
					}
					if (Grid[x][y + 1] == 9) {
						mine_loc++;
					}
					if (Grid[x - 1][y + 1] == 9) {
						mine_loc++;
					}
					if (Grid[x + 1][y + 1] == 9) {
						mine_loc++;
					}
				}
			}
		}
		if (Grid[x][y] != 9) {
			Grid[x][y] = mine_loc;
			mine_loc = 0;
			SafeSpot++;
		}

		Print = true;
		Print_field();
		if (Round == 0)
		{
			do
			{
				cout << "X ve Y cordinatini yazin:" << endl;
				cout << "y:" << endl;
				cin >> x;
				cout << "x:" << endl;
				cin >> y;

				if (x >= Grid_Size) {
					cout << "X sehv yazmisiniz" << endl;
				}
				else if (y >= Grid_Size) {
					cout << "Y-i sehv yazmisiniz" << endl;
				}

			} while (x >= Grid_Size || y >= Grid_Size);
		}
		else if (Round == 1) {
			Start();
		}


		if (Grid[x][y] == 9)
		{
			system("CLS");
			Round = 1;
			defeat();
			cout << "\n" << "   Minaya dusdunuz!   " << endl;
		}

		if (SafeSpot == Round_End) {
			system("CLS");
			cout << "Qalib Geldiniz" << endl;
			Round = 1;
		}


	} while (Round == 0);
	if (Round == 1) {
		Start();
	}
}

void Start() {
	SafeSpot = 0;
	int inpt = 0;
	cout << "\n 1 - Restart \n 2 - Quit" << endl;
	cin >> inpt;
	switch (inpt) {
	case 1:
		system("CLS");
		Round = 0;
		main();
		break;
	case 2:
		system("CLS");
		break;
	default:
		cout << "Sehv Reqem Daxili!" << endl;
		Start();
	}
}
void defeat() {
	for (i = 0; i < Grid_Size; i++)
	{
		for (j = 0; j < Grid_Size; j++)
		{
			if (Grid[i][j] == 9) {
				screen[i][j] = '#';
			}
		}
	}
	cout << "\t\t\t X" << endl;
	cout << "	          ";
	for (i = 0; i < Grid_Size; i++)
	{
		cout << "|" << " " << i << " ";
	}
	cout << "|";
	cout << endl;

	for (i = 0; i < Grid_Size; i++)
	{
		cout << "	   " << line;
		cout << endl;
		for (j = 0; j < Grid_Size; j++)
		{
			if (i != 2 && j == 0) {
				cout << "	      " << "|" << " " << i << " ";
			}
			if (i == 2 && j == 2) {
				cout << "	 Y    " << "|" << " " << i << " ";
			}
		}
		for (j = 0; j < Grid_Size; j++)
		{
			system("Color 04");
			cout << "|" << " " << screen[i][j] << " ";
		}
		cout << "|";
		cout << endl;
		for (j = 0; j < Grid_Size; j++)
		{
			screen[i][j] = ' ';
		}
	}
	cout << endl;
	system("Color 04");

}


void Print_field() {
	if (Print == true) {
		static int temp = 0;
		for (i = 0; i < Grid_Size; i++)
		{
			for (j = 0; j < Grid_Size; j++)
			{
				if (temp != 0) {
					if (x == i && y == j) {
						if (Grid[i][j] == 0)
						{
							screen[i][j] = '0';
						}
						else if (Grid[i][j] == 1) {
							screen[i][j] = '1';
						}
						else if (Grid[i][j] == 2) {
							screen[i][j] = '2';
						}
						else if (Grid[i][j] == 3) {
							screen[i][j] = '3';
						}
						else if (Grid[i][j] == 4) {
							screen[i][j] = '4';
						}
						else if (Grid[i][j] == 5) {
							screen[i][j] = '5';
						}
						else if (Grid[i][j] == 6) {
							screen[i][j] = '6';
						}
						else if (Grid[i][j] == 7) {
							screen[i][j] = '7';
						}
						else if (Grid[i][j] == 8) {
							screen[i][j] = '8';
						}
						else if (Grid[i][j] == 9) {
							screen[i][j] = '#';
						}
					}
				}
				else {
					screen[i][j] = ' ';
				}
			}
		}
		cout << "Bos erazi: " << SafeSpot << endl;
		cout << "\t\t\t X" << endl;
		cout << "	          ";
		for (i = 0; i < Grid_Size; i++)
		{
			cout << "|" << " " << i << " ";
		}
		cout << "|";
		cout << endl;

		for (i = 0; i < Grid_Size; i++)
		{
			if (select_dif == 3) {
				cout << "	     ________" << line;
			}
			else {
				cout << "	   " << line;
			}
			cout << endl;
			for (j = 0; j < Grid_Size; j++)
			{
				if (i != 2 && j == 0) {
					cout << "	      " << "|" << " " << i << " ";
				}
				if (i == 2 && j == 2) {
					cout << "	 Y    " << "|" << " " << i << " ";
				}
			}
			for (j = 0; j < Grid_Size; j++)
			{
				cout << "|" << " " << screen[i][j] << " ";
			}
			cout << "|";
			cout << endl;
		}
		cout << endl;
		temp++;
	}
}