//
// Created by junej on 12/12/2022.
//

#ifndef ZOMBIE_VS_HUMAN_HUMAN_H
#define ZOMBIE_VS_HUMAN_HUMAN_H
#include "organism.h"
#include <string>

using namespace std;

class human : public organism {

protected:

    int recuitCount;

public:
    human();
    ~human();

    int getRecuitCount();
    void setRecuitCount(int r);

    void move(organism* org[][CITY], int i, int j);
    // Human will not breed

    void die(organism* org[][CITY], int i, int j);

    // human survives for three time-steps, at the end of the time step the human will recruit a new human into an adjacent empty space.
    void recruit(organism* org[][CITY], int i, int j);


};


#endif //ZOMBIE_VS_HUMAN_HUMAN_H
