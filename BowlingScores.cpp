
#include <iostream>
#include<fstream>
#include <iomanip>


using namespace std;

const int numberOfPlayers = 11; //Number of players in the file

//Setting up const variables to prevent hard coding
const int divideBy = 5; 
const int scoreRows = 5;

void PrettyPrintResults(char name[][200], int score[][scoreRows], float AverageScore[], int row); //Prints the average along with the scores and names
void GetAverageScores(int score[][scoreRows], float AverageScore[], int row); // Stores the scores and names

int GetBowlingData(char name[][200], int scores[][scoreRows], int& row) //Opens the file

{
	fstream infile("BowlingScores.txt");

	if (infile.is_open())
	{

		while (!infile.eof()) //While file is being read..
		{


			infile >> name[row] >> scores[row][0] >> scores[row][1] >> scores[row][2] >> scores[row][3] >> scores[row][4]; //Stores the list of scores

			row++;


		}
		return true;

	}

	return false;


}


int main()
{



	char name[numberOfPlayers][200];  //Stores the name of the players
	int score[numberOfPlayers][5]; //Stores the scores
	float AverageScore[numberOfPlayers];  //Claculates the average scores based on the score
	int row = 0;

	//Welcome message:
	std::cout << "\n";
	std::cout << "Average scores list" << setw(50) << setfill('*') << endl;
	std::cout << "\n";

	if (GetBowlingData(name, score, row))  //If the file is being read, the following functions will work. 
	{
		GetAverageScores(score, AverageScore, row); //For calculating average results
		PrettyPrintResults(name, score, AverageScore, row); //For printing results
	}
	return 0;


}




void GetAverageScores(int score[][5], float AverageScore[], int row)  //This function calculates the average score
{
	for (int i = 0; i < row; i++) 
	{
		AverageScore[i] = 0; //Average score set to zero for calculation

		for (int r = 0; r < 6; r++) //For r less than 4..
		{
			AverageScore[i] = double(AverageScore[i] + score[i][r]); //Adds the scores for each player
		}

		AverageScore[i] = double(AverageScore[i] / divideBy); //Divides that total score by 4
	}
}

void PrettyPrintResults(char name[][200], int score[][5], float AverageScore[], int row) //Prints the results

{
	char dots = '.';
	char space = ' ';
	char dash = '_';


	for (int i = 0; i <= (row); i++)
	{
		cout << "\nPlayer " << (i + 1) << ": " << name[i] << setw(10) << setfill(dots) << dots << endl;  //Prints the players name
		cout << "Scores: ";


		for (int r = 0; r <= 5; r++)

			cout << score[i][r] << "  "; //Prints the scores

		cout << "\nAverage: " << AverageScore[i] << endl; //Prints the average

		cout << setw(90) << setfill(space) << space << endl; 

	}
}




