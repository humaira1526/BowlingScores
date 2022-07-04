
#include <iostream>
#include<fstream>
#include <iomanip>

using namespace std;

const int numberOfPlayers = 10;

void PrettyPrintResults(char name[][200], int score[][4], float AverageScore[], int row);
int GetBowlingData(char name[][200], int scores[][4], int& row);
void GetAverageScores(int score[][4], float AverageScore[], int row);


int main()
{
	char name[numberOfPlayers][200];
	int score[numberOfPlayers][4];
	float AverageScore[numberOfPlayers];
	int row = 0;

	if (GetBowlingData(name, score, row))
	{
		GetAverageScores(score, AverageScore, row);
		PrettyPrintResults(name, score, AverageScore, row);
	}
	return 0;


}


int GetBowlingData(char name[][200], int scores[][4], int& row)

{
	fstream infile("BowlingScores.txt");

	if (infile.is_open())
	{

		while (!infile.eof())
		{
			infile >> name[row] >> scores[row][0] >> scores[row][1] >> scores[row][2] >> scores[row][3];

			row++;

		}
		return true;

	}

	return false;




}

void GetAverageScores(int score[][4], float AverageScore[], int row)
{
	for (int i = 0; i < row; i++)
	{
		AverageScore[i] = 0;

		for (int r = 0; r <= 3; r++)
		{
			AverageScore[i] += score[i][r];
		}

		AverageScore[i] = AverageScore[i] / 4;
	}
}

void PrettyPrintResults(char name[][200], int score[][4], float AverageScore[], int row)

{
	char dots = '.';
	char space = ' ';
	char dash = '_';


	for (int i = 0; i <= (row); i++)
	{
		cout << "Player " << (i + 1) << ": " << name[i] << setw(10) << setfill(dots) << dots << endl;
		cout << "Scores: ";


		for (int r = 0; r <= 3; r++)

			cout << score[i][r] << "  ";

		cout << "\nAverage: " << AverageScore[i] << endl;

		cout << setw(90) << setfill(space) << space << endl;

	}
}




