//
// Created by junej on 12/12/2022.
//

#include "city.h"
#include "zombie.h"
#include "human.h"

#include <iostream>
#include <string>
using namespace std;


city::city() {

    // reset the city
    for(int i = 0 ; i < CITY; i++) {
        for (int j = 0; j < CITY; j++) {
            organismXY[i][j] = nullptr;
        }
    }

    // random start with zombie
    int orgCount = 0;
    while(orgCount < SNZ) {
        int i = (rand() % CITY);
        int j = (rand() % CITY);
        if (organismXY[i][j] == nullptr) {
            organismXY[i][j] = new zombie;
            orgCount++;
        }
    }
    // rand human start
    orgCount = 0;
    while(orgCount < SNH) {
        int i = (rand() % CITY);
        int j = (rand() % CITY);
        if (organismXY[i][j] == nullptr) {
            organismXY[i][j] = new human;
            orgCount++;
        }
    }

}


city::~city(){
    //delete the city
    for (int i = 0; i < CITY; i++) {
        for(int j = 0; j < CITY; j++) {
            delete organismXY[i][j];
        }
    }
}



void city::generation() {
    genCount++; // increase generation count
    for (int i = 0; i < CITY; i++) {
        for (int j = 0; j < CITY; j++) {
            if (organismXY[i][j] != nullptr) { //only act on indexes containing organisms
                if (organismXY[i][j]->getName() == "Zombie") {
                    organismXY[i][j]->setHasMoved(false);//reset all zombies to not moved

                }
                else if (organismXY[i][j]->getName() == "Human") {
                    organismXY[i][j]->setHasMoved(false);//reset all human to not moved
                }
            }
        }
    }
    ///zombie round action/////////
    //zombie move/eat
    for(int i = 0; i < CITY; i++) {
        for(int j = 0; j < CITY; j++){
            if((organismXY[i][j] != nullptr) && (organismXY[i][j] ->getName() == "Zombie") && (organismXY[i][j]->getHasMoved()==false)) {
                // if zombie move in the [][] than count lifespan and starve
                organismXY[i][j]->setLifespan(1); // this zombie, lifespan increase
                organismXY[i][j] ->move(organismXY, i, j); // initiate move

            }
        }
    }
    //zombie breed a new zombie  // Testing should set back to 8
    for(int i = 0; i < CITY; i++) {
        for(int j = 0; j < CITY; j++){
            if((organismXY[i][j] != nullptr) && (organismXY[i][j]->getName() == "Zombie")) {
                if(organismXY[i][j]->getLifespan() == ZOMBIE_BREED) {// breed after 8 time-step
                    organismXY[i][j]->breed(organismXY, i, j);// initiate breeding
                }
            }
        }
    }
    //!!!!!zombie return human after not eat for 3-time step !!!!!
    for(int i =0; i < CITY; i++) {
        for(int j = 0; j <CITY; j++) {
            if((organismXY[i][j] != nullptr) && (organismXY[i][j]->getName() == "Zombie")) {
                if(organismXY[i][j]->getStarve() == ZOMBIE_STARVE) {
                    // call the method
                    organismXY[i][j]->rebornHuman(organismXY, i, j);

                }
            }
        }
    }

    /// human round action ///
    for (int i = 0; i < CITY; i ++) {
        for(int j =0; j < CITY; j++) {
            if((organismXY[i][j] != nullptr) && (organismXY[i][j] ->getName() == "Human") && (organismXY[i][j]->getHasMoved()==false)){
                organismXY[i][j]->setLifespan(1);
                organismXY[i][j]->move(organismXY, i, j);
            }
        }
    }
    //human recuit
    for(int i=0; i <CITY; i++) {
        for(int j =0; j < CITY; j++){
            if((organismXY[i][j] != nullptr) && (organismXY[i][j] ->getName() == "Human")) {
                if(organismXY[i][j] -> getLifespan()== HUMAN_RECRUIT) {
                    // call the method in the child class
                    organismXY[i][j]->recruit(organismXY, i, j);
                    organismXY[i][j]->setRecuitCount(0);

                }
            }
        }
    }
    /// end zombie && human round ///
    zombieCount = 0;
    humanCount = 0;
    for(int i = 0; i < CITY; i++) {
        for(int j = 0; j < CITY; j++) {
            if(organismXY[i][j] != nullptr) {
                if (organismXY[i][j] -> getName() == "Zombie") {
                    zombieCount++;
                    organismXY[i][j] ->setHasMoved(false);
                }
                else if(organismXY[i][j]->getName()=="Human") {
                    humanCount++;
                    organismXY[i][j]->setHasMoved(false);
                }
            }
        }
    }
    // after clear the gen
    cout << "After " << genCount << "timesteps: Zombies amount: "<<zombieCount<<"/ Human amount: "<<humanCount<<endl;
    printCityMap();

}

// ostream
//ostream& operator<<(ostream& os, city& c){
//    cout << "Organism amount: "<<"Zombie amount: " <<SNZ << "/ Human amount: " <<SNH <<endl;
//    c.printCityMap();
//}



void city::printCityMap() {

        for (int i = 0; i < CITY; i++) {
            for (int j = 0; j < CITY; j++) {
                if(zombieCount == 0 || humanCount == 0) {
                    throw "extinction event happened";
                }

                if (organismXY[i][j] == nullptr) {
                    organismXY[i][j]->setConsoleTextColour(7);
                    cout << "+ ";
                } else if (organismXY[i][j]->getName() == "Zombie") {
                    organismXY[i][j]->setConsoleTextColour(12);
                    cout << organismXY[i][j]->getSymbol();
                } else if (organismXY[i][j]->getName() == "Human") {
                    organismXY[i][j]->setConsoleTextColour(3);
                    cout << organismXY[i][j]->getSymbol();
                } else {

                }

            }
            cout << endl; // print new row after every loop
        }
        cout << "end of a time step" << endl;

}


