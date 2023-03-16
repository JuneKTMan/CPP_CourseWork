#include <iostream>
#include <vector>

#include "../inc/searcher.hpp"

#define COLLECTION_SIZE 10000000
#define ITEM_TO_FIND 568236
#define ITEM_TO_NOT_FIND 362789

using namespace std;


int main() {

    vector<int> targetCollection; // N is size of this vector

    // We will populate our target vector with COLLECTION_SIZE even numbers starting at 2
    for(int i = 1; i <= COLLECTION_SIZE; i++) {
        targetCollection.push_back(i * 2);
    }


    // PART 1 - use the existing LOOPING function
    if(isTargetPresentLooping(ITEM_TO_FIND, targetCollection)) {
        cout << "Part 1 - Found " << ITEM_TO_FIND << " in vector." << endl;
    }
    else{
        cout << "Part 1 - Did not find " << ITEM_TO_FIND << " in vector." << endl;
    }

    cout << endl;

    if(isTargetPresentLooping(ITEM_TO_NOT_FIND, targetCollection)) {
        cout << "Part 1 - Found " << ITEM_TO_NOT_FIND << " in vector." << endl;
    }
    else{
        cout << "Part 1 - Did not find " << ITEM_TO_NOT_FIND << " in vector." << endl;
    }

    cout << endl;

    // PART 2 - use the new RECURSIVE function
    if(isTargetPresentRecursive(ITEM_TO_FIND, targetCollection, 0, COLLECTION_SIZE - 1)) {
        cout << "Part 2 - Found " << ITEM_TO_FIND << " in vector." << endl;
    }
    else{
        cout << "Part 2 - Did not find " << ITEM_TO_FIND << " in vector." << endl;
    }

    cout << endl;

    if(isTargetPresentRecursive(ITEM_TO_NOT_FIND, targetCollection, 0, COLLECTION_SIZE - 1)) {
        cout << "Part 2 - Found " << ITEM_TO_NOT_FIND << " in vector." << endl;
    }
    else{
        cout << "Part 2 - Did not find " << ITEM_TO_NOT_FIND << " in vector." << endl;
    }


    cout << endl;


    // Output Time Complexity of Different Operations
    cout << "Big O Analysis:" << endl;
    cout << "Time complexity of isTargetPresentLooping function: O(log N)" << std::endl;
    cout << "Time complexity of isTargetPresentRecursive function: O(log N)" << std::endl;


    return 0;
}
