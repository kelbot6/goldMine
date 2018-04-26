//Kelly Morgan
//CPSC 340
//9 October 2017
/*
This file declares all necessary methods/functions for the Box class.
*/
#ifndef BOXH
#define BOXH
#include <string>

using namespace std;

class Box {
	public:
		Box();
		bool getVisited() const;
		void setVisited(bool visited);
		int getGoldLost() const;
		void setGoldLost(int amount);
		char getCharacter() const;
		void setCharacter(char special);
	private:
		char character;
		int goldLost;
		bool selected;
};

#endif
