//
// Created by junej on 12/12/2022.
//

#ifndef ZOMBIE_VS_HUMAN_CITY_H
#define ZOMBIE_VS_HUMAN_CITY_H
#include "organism.h"
#include "gobalVar.h"
#include "zombie.h"
#include "human.h"
#include "vector"
#include "string"
#include "process.h"
#include <stdlib.h>

using namespace std;

class organism;

class city {

private:
    //pointer to orgainism location
    organism* organismXY[CITY][CITY];
    //count the whole generation record
    int genCount = 0;
    int zombieCount = 0;
    int humanCount = 0;
    vector<city >printCity;

public:
    city();
    ~city();

    void generation();
    void printCityMap();

    friend ostream& operator<<(ostream &os, city& c);
};

ostream& operator<<(ostream& os, city& c);


#endif //ZOMBIE_VS_HUMAN_CITY_H
