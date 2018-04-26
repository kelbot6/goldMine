//Kelly Morgan
//CPSC 340
//9 October 2017
/*
   This class populates the game board with the Goldmine, Coal, and Rainbow
   locations, as well as prints the board.
 */
#ifndef GOLDMINECPP
#define GOLDMINECPP
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <ctime>
#include "Goldmine.h"
#define SIZE 6
using namespace std;

GoldMine::GoldMine(){

	int gold = 1000;
	srand(time(0)%INT_MAX);
	//initialGold = rand() % 2001 + 1000;
	int randLost = rand() % 101;
	goldRow = 0;
	goldCol = 0;
	coalRow = 0;
	coalCol = 0;
	rainRow = 0;
	rainCol = 0;
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			gm[i][j].setGoldLost(randLost);
			gm[i][j].setCharacter('N');
			gm[i][j].setVisited(false);
		}
	}
	this->setMyBox('G');
	this->setMyBox('C');
	this->setMyBox('R');
	int row = -1;
	int column = -1; 
} 

void GoldMine::randomRowColumn(int &row, int &column){
	do{
		row = rand() % 6;
		column = rand() % 6;
		//cout<< "row = " << row << "col=" << column << gm[row][column].getCharacter()<<endl;

	} while (gm[row][column].getCharacter() != 'N');
}
void GoldMine::setMyBox(char c){
	if (c == 'C'){
		setCoal();	
	}
	if (c == 'G'){
		setGold();
	}
	if (c == 'R'){	
		setRainbow();	
	}	
}

void GoldMine::setRainbow(){
	randomRowColumn(rainRow, rainCol);
	gm[rainRow][rainCol].setCharacter('R');  
	cout << "Rainbow is located at row: " << rainRow << " and column: " <<rainCol << endl;
}

void GoldMine::setGold(){
	randomRowColumn(goldRow, goldCol);
	gold = rand() % 1001;
	cout << "Gold is located at row: " << goldRow << " and column: " << goldCol << endl;
	gm[goldRow][goldCol].setCharacter('G');
	//set gold to high amount
	//set character to g

}

void GoldMine::setCoal(){
	randomRowColumn(coalRow, coalCol);
	cout << "Coal is located at row: " << coalRow << " and column: " << coalCol << endl;
	gm[coalRow][coalCol].setCharacter('C');
}

string GoldMine::rainbowMessage(){
	if ((goldRow >= 0 && goldRow <= 2) && (goldCol >= 0 && goldCol <= 2))//northwest
		return ("The pot of gold is in the northwest section!");

	else if ((goldRow >= 0 && goldRow <= 2) && (goldCol >= 3 && goldCol <= 5))//northeast
		return ("The pot of gold is in the northeast section!");

	else if ((goldRow >= 3 && goldRow <= 5) && (goldCol >= 0 && goldCol <= 2))//southwest
		return ("The pot of gold is in the southwest section!");

	else if ((goldRow >= 3 && goldRow <= 5) && (goldCol >= 3 && goldCol <= 5))//southeast
		return ("The pot of gold is in the southeast section!");
}

char GoldMine::revealSelection(int row, int column){
	if (gm[row][column].getCharacter() == 'N'){
		if (!gm[row][column].getVisited()){
			gm[row][column].setVisited(true);
		}
		//cout << "character is N" << endl;
	}
	else if (gm[row][column].getCharacter() == 'R'){
		if (!gm[row][column].getVisited()){
			gm[row][column].setVisited(true);
		}
		cout << rainbowMessage();
		//cout << "character is R" << endl;
	}
	else if (gm[row][column].getCharacter() == 'G'){
		if (!gm[row][column].getVisited()){
			gm[row][column].setVisited(true);
		}
		cout << "You win!" << endl;
		//cout << "character is G" << endl;
	}
	else if (gm[row][column].getCharacter() == 'C'){
		if (!gm[row][column].getVisited()){
			gm[row][column].setVisited(true);
		}
		cout << "You lose :(" << endl; 
		//cout << "character is C" << endl;
	}
	return gm[row][column].getCharacter();
}

void GoldMine::printGoldMine(){
	int rowCount = 0;
	cout << "   0    1    2    3    4    5" << endl;
	for (int i = 0; i < SIZE; i++){
		cout << rowCount;
		rowCount++; 
		for (int j = 0; j < SIZE; j++){
			if (gm[i][j].getVisited() == false){
				cout << "  *  ";
				//cout << "position not visited" << endl;
			}
			else {
				//cout << "position visited" << endl;	
				if (gm[i][j].getCharacter() == 'N')
					cout << "  -  ";	
				else
					cout << "  " << gm[i][j].getCharacter() << "  ";
			}
		}
		cout << endl;
	}
}

int GoldMine::getGold(){
	return gold;
}

#endif
