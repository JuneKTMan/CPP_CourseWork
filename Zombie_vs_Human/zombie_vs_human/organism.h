//
// Created by junej on 12/12/2022.
//

#ifndef ZOMBIE_VS_HUMAN_ORGANISM_H
#define ZOMBIE_VS_HUMAN_ORGANISM_H

#include <iostream>
#include <cstdlib>//needed for random
#include <string>
#include <windows.h>
#include <conio.h>
#include "gobalVar.h"


using namespace std;

class city;

class organism {

protected:

    string name;
    char symbol; // Z/H
    int lifespan; // to measure how many timesteps of this organism
    int starve;
    bool hasMoved;
    int recuitCount;
    int colour;

public:
    // no argument
    organism();
    // constructor
    organism(string name, char symbol, int lifespan, int colour, int starve, bool hasMoved);
    //destructor deallocates the memory
    ~organism();

    string getName();
    char getSymbol();
    int getLifespan();
    int getcolour();
    int getStarve();
    bool getHasMoved();
    void setConsoleTextColour(int colour);
    void setLifespan(int ls);
    void setStarve(int s);
    void setHasMoved(bool m);

    int getRecuitCount();
    void setRecuitCount(int r);

    virtual void move(organism* org[][CITY], int i , int j);
    virtual void breed(organism* org[][CITY], int i, int j);
    virtual void die(organism* org[][CITY], int i, int j);
    virtual void rebornHuman(organism* org[][CITY], int i, int j);
    virtual void recruit(organism* org[][CITY], int i, int j);



};


#endif //ZOMBIE_VS_HUMAN_ORGANISM_H
