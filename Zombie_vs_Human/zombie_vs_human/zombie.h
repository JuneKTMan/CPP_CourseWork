//
// Created by junej on 12/12/2022.
//

#ifndef ZOMBIE_VS_HUMAN_ZOMBIE_H
#define ZOMBIE_VS_HUMAN_ZOMBIE_H
#include "organism.h"
#include <string>
#include "gobalVar.h"
using namespace std;

class zombie : public organism {

public:
    zombie();
    ~zombie();

    void move(organism* org[][CITY], int i , int j);
    void breed(organism* org[][CITY], int i, int j);

    void rebornHuman(organism* org[][CITY], int i, int j);

};


#endif //ZOMBIE_VS_HUMAN_ZOMBIE_H
