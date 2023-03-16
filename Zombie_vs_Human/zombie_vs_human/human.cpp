//
// Created by junej on 12/12/2022.
//

#include "human.h"
#include <string>
using namespace std;

human::human(): organism("Human",'H', 0, 3, 0, false) {

}

human::~human(){

}

int human::getRecuitCount() {
    return recuitCount;
}

void human::setRecuitCount(int r) {
    recuitCount = 0;
}

//i + 1 = row down || i - 1 = row up || j + 1 = col right || j - 1 = col left
// human only move, not eat
void human::move(organism *(*org)[CITY], int i, int j) {
    int direction = (rand()%4); // random 4 direction
    switch(direction) {
        case 0:
            if((j > 0) && (org[i][(j -1)] == nullptr)) {
                org[i][(j - 1)] = org[i][j]; // left  org[i-1][(j)] = org [i][j]; up
                org[i][(j -1)] ->setHasMoved(true);
                org[i][j] = nullptr;
            }
            break;
        case 1:
            if((i > 0) && (org[(i-1)][(j)] == nullptr)) {
                org[(i-1)][j] = org[i][j]; // up  //  org[i][(j + 1)] = org[i][j]; right
                org[(i-1)][j] ->setHasMoved(true);
                org[i][j] = nullptr;
            }
            break;
        case 2:
            if ((j < CITY -1) && (org[i][(j + 1)] == nullptr)) {
                org[i][(j + 1)] = org[i][j]; // right  // org[(i + 1)][j] = org[i][j];  down
                org[i][(j + 1)]->setHasMoved(true);
                org[i][j] = nullptr;
            }
            break;
        case 3:
            if ((i < CITY -1) && (org[(i + 1)][j] == nullptr)) {
                org[(i + 1)][j] = org[i][j]; // down // org[i][(j - 1)] = org[i][j]; // left
                org[(i + 1)][j]->setHasMoved(true);
                org[i][j] = nullptr;
            }
            break;
    }
}


void human::die(organism *(*org)[CITY], int i, int j) {
    delete org[i][j];
    org[i][j] = nullptr;
}

void human::recruit(organism *(*org)[CITY], int i, int j) {//checking down for "not out of bounds" and empty
    if ((i > 0) && (org[(i - 1)][j] == nullptr)) {
        org[(i - 1)][j] = new human; // recuit new human
        org[i][j]->setRecuitCount(0);
    }
    else if ((j < CITY -1) && (org[i][(j + 1)] == nullptr)) { //checking right for "not out of bounds" and empty
        org[i][(j + 1)] = new human; //recuit new human
        org[i][j]->setRecuitCount(0);
    }
    else if ((i < CITY-1) && (org[(i + 1)][j] == nullptr)) { //checking up for "not out of bounds" and empty
        org[(i + 1)][j] = new human; //recuit new human
        org[i][j]->setRecuitCount(0);
    }
    else if ((j > 0) && (org[i][(j - 1)] == nullptr)) { //checking left for "not out of bounds" and empty
        org[i][(j - 1)] = new human; //recuit new human
        org[i][j]->setRecuitCount(0);
    }
    else {
        //no cell to recuit
    }
}