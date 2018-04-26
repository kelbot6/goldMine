//Kelly Morgan
//CPSC 340
//9 October 2017
/*
This class sets up the game board for the game, by setting all boxes to 'N' and not visited initially, as well as setting how much gold is lost per box.
*/
#ifndef BOXCPP
#define BOXCPP

#include <iostream>
#include <string>
#include "Box.h"
using namespace std;

Box::Box() {
	character = 'N';
	goldLost = 0;
	selected = false;
}

bool Box::getVisited() const{
	return selected;
}

void Box::setVisited(bool visited){
	selected = visited;
}

int Box::getGoldLost() const{
	return goldLost;
}

void Box::setGoldLost(int amount){
	this->goldLost = amount;	
}

char Box::getCharacter() const{
	return character;
}

void Box::setCharacter(char special){
 	this->character = special;	
}

#endif 
