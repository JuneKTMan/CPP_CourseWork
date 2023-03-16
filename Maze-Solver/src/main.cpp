#include <iostream>
#include <fstream>
//#include <stack>
#include <time.h>
#include <vector>

#include "../inc/container.hpp"

using namespace std;

const int MAZE_SIZE = 50; //50
const char WALL = '|';
const char UD_WALL = '-';
const char CORNER = '+'; // can find the path after find is
const char PATH = '#';
const char FREE = ' ';
const char START = 'S'; //(1,1)
const char END = 'E'; //(49, 50)



class Maze {

public:
    // set vector to store the maze
    vector<vector<char>> cells;
    pair<int, int> start;
    pair<int, int> end;
};


Maze readMaze(string filename) {

    Maze maze;
    ifstream inFile(filename);
    if(inFile.is_open()) {

        string line;
        int row = 0;
        while(getline(inFile, line)) {
            vector<char> cells;
            for(int col = 0; col < line.length(); col++) { // read the col of every
                char c = line[col];
//                if(c == START) {
//                    maze.start = {0, 1}; // row col
//                }else if ( c == END) {
//                    maze.end = {50, 49}; //row col
//                }
                cells.push_back(c);
            }
            maze.cells.push_back(cells);
            row++;
        }
        inFile.close();
    }
    return maze;
}

void printMaze(const Maze& maze) {
    // set the maze a grid, the col number  = row number
    for(int row = 0; row < maze.cells.size(); row++) {
        for (int col = 0; col < maze.cells[row].size(); col++) {
            cout << maze.cells[row][col];
        }
        cout << endl;
    }
}



void solveMazeDFS(const Maze& maze){

    Container *locationStack = new Container();

    MapLocation *newLocation = new MapLocation();
    newLocation->x = 0;
    newLocation->y = 1;
    newLocation->isExplored = false;
    newLocation->previous = nullptr;

    locationStack->push(newLocation);


    while(locationStack->peek()!= nullptr) {
       Node* currentNode = locationStack->peek();

       MapLocation* currentLocation = currentNode->getValue();

       //if maplocation isExplored pop and continues
       if(currentLocation->isExplored != false) {
           locationStack->pop();
           continue;
       }

       // if end of Maze then we are done - trace backpath
       if(currentLocation->x == 50){
           cout << "Found exit at X: " << currentLocation->x << " Y: " <<currentLocation->y << endl;

           MapLocation* getbackLocation = currentLocation->previous;
           Maze maze;
           //starting at the current location, keep going to the previous location and until reach the start, x 0, y 1 - backtrace
           while (getbackLocation != nullptr && (getbackLocation->x != 0 || getbackLocation->y != 1)) {

               if(locationStack->isEmpty()){
                   break;
               }

               MapLocation* currentLocation = getbackLocation;
               getbackLocation = getbackLocation->previous;
               locationStack->pop();
//               delete currentLocation;

                //find the previous location and replace with "#"
               maze.cells[currentLocation->y][currentLocation->x] = PATH;

               //cout<< "#";
           }

           break;
       }


       // if not, mark the current location as explored
       currentLocation->isExplored = true;

        //Needs to get previous maplocation
        MapLocation *previousLocation = currentLocation->previous;

        // Check up direction first
        if(currentLocation->y > 0 && maze.cells[currentLocation->y-1][currentLocation->x] == FREE){
            if(previousLocation == NULL || previousLocation->x != currentLocation->x || previousLocation->y != currentLocation->y - 1) {
                MapLocation* upLocation =  new MapLocation();
                upLocation->x = currentLocation->x;
                upLocation->y = currentLocation->y-1;
                upLocation->isExplored = false;
                upLocation->previous = currentLocation;
                locationStack->push(upLocation);

            }
        }
        //Check left dir next
        if(currentLocation->x > 0 && maze.cells[currentLocation->y][currentLocation->x -1] == FREE){
            if(previousLocation == NULL || previousLocation->x != currentLocation->x-1 || previousLocation->y != currentLocation->y) {
                MapLocation* leftLocation =  new MapLocation();;
                leftLocation->x = currentLocation->x -1 ;
                leftLocation->y = currentLocation->y;
                leftLocation->isExplored = false;
                leftLocation->previous = currentLocation;
                locationStack->push(leftLocation);
            }

        }
        //Check down dir next
        if(currentLocation->y < 50 && maze.cells[currentLocation->y + 1][currentLocation->x] == FREE){
            if(previousLocation == NULL ||  previousLocation->x != currentLocation->x || previousLocation->y != currentLocation->y + 1) {
                MapLocation* downLocation =  new MapLocation();
                downLocation->x = currentLocation->x ;
                downLocation->y = currentLocation->y + 1;
                downLocation->isExplored = false;
                downLocation->previous = currentLocation;
                locationStack->push(downLocation);
            }

        }

        //Check right dir next
        if(currentLocation->x < 50 && maze.cells[currentLocation->y][currentLocation->x + 1] == FREE){

                if(previousLocation == NULL || previousLocation->x != currentLocation->x + 1 || previousLocation->y != currentLocation->y) {
                    MapLocation* rightLocation =  new MapLocation();
                    rightLocation->x = currentLocation->x + 1 ;
                    rightLocation->y = currentLocation->y;
                    rightLocation->isExplored = false;
                    rightLocation->previous = currentLocation;
                    locationStack->push(rightLocation);

                }


        }


    }


}



int main() {

    // YOUR CODE SHOULD GO HERE
    // BE AWARE THE MAKEFILE IS ALSO EXPECTING A SECOND CPP FILE FOR THE CONTAINER


    string filepath;
    filepath = "..\\sample-files\\sample_maze.txt";

    Maze maze = readMaze(filepath);
    printMaze(maze);
    solveMazeDFS(maze);
//  printMaze(maze);



    return 0;


}
