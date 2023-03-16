//
// Created by junej on 12/12/2022.
//

#include "zombie.h"
#include "human.h"
#include <string>
#include "gobalVar.h"
#include <windows.h>
using namespace std;

zombie::zombie():organism("Zombie",'Z',0,12,0,false)
{

}
zombie::~zombie() {}

//i + 1 = row down || i - 1 = row up || j + 1 = col right || j - 1 = col left
// check every i (row) j (col) // row, down, left col up, left , right
// move including if eating else starving
void zombie::move(organism * org[][CITY], int i, int j)

{

    //checking for row (down) not empty and has human, if get human
    if((i > 0) && (org[i-1][j] !=nullptr) && (org[i][j] ->getName() == "Human")) {
        org[(i - 1)][j]->die(org, (i - 1), j); //Move encountered human then eat
        org[i][j]->setStarve(0);// reset to starve level to 0 after ate a human
        org[(i-1)][j]->setHasMoved(true); // after confirm ate a human then -1, eat/move, cover the human cell in this timestep
        org[i][j] = nullptr; // empty the original location << because z moved to left or right or up or down to cover the H cell;

    }else if ((j < CITY -1) && (org[i][j+1] !=nullptr) && (org[i][j+1]->getName() == "Human")) {
        org[i][(j+1)] ->die(org, i, (j+1)); // eat human
        org[i][j]->setStarve(0);// reset to 0 after ate
        org[i][(j+1)] = org [i][j];//move to new cell
        org[i][(j+1)] ->setHasMoved(true);
        org[i][j] = nullptr; // empty original location

    }
    // checking down
    else if ((i < CITY -1 ) && (org[(i +1)][j] != nullptr) && (org[i+1][j] ->getName() == "Human")) {
        org[(i + 1)][j] ->die(org, (i+1), j); // eat human
        org[i][j]->setStarve(0); // reset starve level
        org[(i + 1)][j] = org[i][j];//move to new cell
        org[i+ 1][j] ->setHasMoved(true); // moved
        org[i][j] = nullptr;// empty original cell
    }
    else if (( j > 0) && (org[i][(j - 1)] != nullptr) && (org[i][j-1] ->getName() == "Human")){
        org[i][(j - 1)]->die(org, i, (j-1));
        org[i][j]->setStarve(0);// reset to 0 after ate
        org[i][(j-1)] = org [i][j];//move to new cell
        org[i][(j-1)] ->setHasMoved(true);
        org[i][j] = nullptr; // empty original location

    }
    else{// starving

        org[i][j] ->setStarve(1); // No human to eat. increase starve level
        int direction = (rand() %4); // Up, down, left, right

        switch(direction) {
            case 0:
                if(((j > 0) && (org[i][(j - 1)] == nullptr))) { // not out of city not empty
                    org[i][(j-1)] = org[i][j]; // move new cell
                    org[i][(j-1)] ->setHasMoved(true);
                    org[i][j] = nullptr; // empty original cell
                }
                break;
            case 1:
                if ((i > 0) && (org[(i - 1)][j] == nullptr)) {
                    org[(i - 1)][j] = org[i][j]; //move to new location
                    org[(i - 1)][j]->setHasMoved(true);//mark organism as having moved this turn
                    org[i][j] = nullptr;//empty original location
                }
                break;
            case 2:
                if ((j < CITY - 1) && (org[i][(j + 1)] == nullptr)) { // 19 not out of bound
                    org[i][(j + 1)] = org[i][j];//move to new location
                    org[i][(j + 1)]->setHasMoved(true);
                    org[i][j] = nullptr;//empty original location
                }
                break;
            case 3:
                if ((i < CITY - 1) && (org[(i + 1)][j] == nullptr)) {
                    org[(i + 1)][j] = org[i][j];//move to new location
                    org[(i + 1)][j]->setHasMoved(true);
                    org[i][j] = nullptr;//empty original location
                }
                break;
        }

    }

}

void zombie::breed(organism* org[][CITY], int i, int j){
    if ((i > 0) && (org[(i - 1)][j] == nullptr)) { //checking up for "not out of bounds" and empty
        org[(i - 1)][j] = new zombie; //breed new zombie

    }
    else if ((j < CITY - 1) && (org[i][(j + 1)] == nullptr)) { //checking right for "not out of bounds" and empty
        org[i][(j + 1)] = new zombie; //breed new zombie

    }
    else if ((i < CITY - 1) && (org[(i + 1)][j] == nullptr)) { //checking down for "not out of bounds" and empty
        org[(i + 1)][j] = new zombie; //breed new zombie

    }
    else if ((j > 0) && (org[i][(j - 1)] == nullptr)) { //checking left for "not out of bounds" and empty
        org[i][(j - 1)] = new zombie; //breed new zombie

    }
    else {
        // no cell, can't breed
    }
};



// zombie not eat for three time step then will return to human
void zombie::rebornHuman(organism *(*org)[CITY], int i, int j) {
        delete org[i][j];//deletes organism object
        org[i][j] = nullptr;
        org[i][j] = new human; //breed new human

}