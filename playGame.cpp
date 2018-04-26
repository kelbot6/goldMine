//Kelly Morgan
//CPSC 340
//9 October 2017
/*
   This program generates a random game board, and allows the user to guess
   different boxes to try and select the Goldmine to win. If the user selects
   Coal, they lose, and if they find the Rainbow, it will tell them which 
   section the Goldmine is in. Whenever they find a box that isn't the 
   Goldmine, Coal, or Rainbow, they will lose gold. If they run out of gold
   they lose.
 */
#include <string>
#include <iostream>
#include "Goldmine.h"
#include "Box.h"
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <ctime>

using namespace std;

int main(){
	int initialGold = 1000;
	//	srand(time(0)%INT_MAX);
	//	initialGold = rand() % 2001 + 1000;
	int usrRow = 0;
	int usrCol = 0;
	string playAgain = "yes";


	while (usrRow != -1 && usrCol != -1){
		while (playAgain.compare("yes") == 0){
			GoldMine gm;
			Box  boxChar;
			gm.printGoldMine();
			while (boxChar.getCharacter()!= 'C' && boxChar.getCharacter() != 'G' && (gm.getGold() >= 0)){

				//gm.revealSelection(usrRow, usrCol) != 'C' || gm.revealSelection(usrRow, usrCol) != 'G'){

				cout << "What row would you like to check? (-1 to quit)" << endl;
				cin >> usrRow;
				while (usrRow >= 6){
					cin.ignore();
					cout << "Please enter a valid row (0-6)." << endl;
					cin >> usrRow;
				}

				cout << "What column would you like to check? (-1 to quit)" << endl;
				cin >> usrCol;
				while (usrCol >= 6){
					cin.ignore();
					cout << "Please enter a valid column (0-6)." << endl;
					cin >> usrCol;
				}
				//cout << "after row/col selections" << endl;
				boxChar.setCharacter(gm.revealSelection(usrRow, usrCol));
				gm.printGoldMine();
				//cout << "after reveal selection" << endl;
				//gm.printGoldMine();
			}
			//usrRow = -1;
			//usrCol = -1;
			//cout << "second print" << endl;
			cout << "Play again? (yes or no)" << endl;
			cin >> playAgain;
			cout << "PlayAgain string is " << playAgain << playAgain.compare("yes")<<endl;
			}
			usrRow = -1;
			usrCol = -1;
			cout << "You quit!" << endl;
			/*else {
			  usrRow = -1;
			  usrCol = -1;
			  cout << "You quit!" << endl;
			  }*/
		}//end of -1 while loop
	}//end of main
