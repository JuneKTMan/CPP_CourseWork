#include <iostream>
#include "organism.h"
#include "city.h"
#include <windows.h>
#include <chrono>
#include <thread>



int main() {
    cout << "-------------------------  Zombie VS Human   -------------------------" << endl;
    city raccoon;


    // Run the city map and catch exception
    try{
    for (int i = 0; i < ITERATIONS; i++){
        raccoon.generation();
        Sleep(PAUSE_MILLISECONDS);
    }
    }catch (const char* msg) {
        cerr << msg <<endl;

    }

    return 0;
}


