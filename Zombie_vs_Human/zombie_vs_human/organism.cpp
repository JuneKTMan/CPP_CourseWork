//
// Created by junej on 12/12/2022.
//

#include "organism.h"

#include <string>

using namespace std;
// define constructor
organism::organism():name("organism"), symbol('O'), lifespan(0), colour(0), starve(0), hasMoved(false)
{

}

organism::organism(string name, char symbol, int liftspan, int colour, int starve, bool hasMoved)
: name(name), symbol(symbol), lifespan(liftspan), colour(colour), starve(starve), hasMoved(false)
{

}

//destructor
organism::~organism()
{
 //deallocates the memory
}

//get the organism name
string organism::getName() {
    return name;
}

char organism::getSymbol() {
    return symbol;
}

int organism::getLifespan() {
    return lifespan;
}

void organism::setLifespan(int ls) {
    if (ls > 0)
        lifespan = lifespan + ls; //increase lifespan count

}

int organism::getcolour(){
    return colour;
}

void organism::setConsoleTextColour(int colour){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colour);
}

int organism::getStarve() {
    return starve;
}
void organism::setStarve(int s){
    if (s > 0){
        starve = starve + s;
    }else{
        starve = 0; // reset starve record (if eat)
    }

}
bool organism::getHasMoved() {
    return hasMoved;
}
// make it virtual??
void organism::setHasMoved(bool m) {
    hasMoved = m; // move or !move
}

int organism::getRecuitCount() {
    return recuitCount;
}

void organism::setRecuitCount(int r) {
    //Something need to edit here if recruited
    recuitCount = 0;
}
// action will take in child class
void organism::move(organism * org[][CITY], int i, int j)
{
}

void organism::breed(organism * org[][CITY], int i, int j)
{
}

void organism::die(organism * org[][CITY], int i, int j)
{
    delete org[i][j];
    org[i][j] = nullptr;

}

void organism::rebornHuman(organism *(*org)[CITY], int i, int j) {

}

void organism::recruit(organism *(*org)[CITY], int i, int j) {

}
