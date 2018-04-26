//Kelly Morgan
//CPSC 340
//9 October 2017
/*
This file declares the necessary methods/variables to be used in the
Goldmine.
*/
#ifndef GOLDMINEH 
#define GOLDMINEH
#include <string>
#include "Box.h"
using namespace std;

class GoldMine{
	public: 
		GoldMine();
		void randomRowColumn(int &row, int &column);
		void setMyBox(char c);
		void setRainbow();
		void setGold();
		void setCoal();
		string rainbowMessage();
		char revealSelection(int row, int column);
		void printGoldMine();
		int getGold(); //{return gold;};
	private:
		Box gm[6][6];
		int gold;
		int goldRow;
		int goldCol;
		int coalRow;
		int coalCol;
		int rainRow;
		int rainCol;
};

#endif
