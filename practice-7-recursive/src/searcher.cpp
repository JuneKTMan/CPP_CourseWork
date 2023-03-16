#include "../inc/searcher.hpp"

// global variable to show recursion count
int functionCount = 0;

// This function will find if a number is in the collection.
// It assumes the collection is sorted (in Ascending order).
bool isTargetPresentLooping(int target, vector<int> &sortedCollection) {

    bool    isFound = false;
    int     startItem, endItem, middleItem, count = 0;
    int     collectionSize = sortedCollection.size();

    // start the middle item halfway through the collection
    // the startItem at the beginning, and endItem at the end
    startItem = 0;
    endItem = collectionSize - 1;
    middleItem = (endItem - startItem) / 2 + startItem;

    // we will terminate the loop is we found the number or our middle pointer
    // reaches the start or end items
    while(isFound == false && middleItem != startItem && middleItem != endItem ) {

        count++;

        cout << "Loop running " << count << " times." << std::endl;

        // if the current item is greater than the target, adjust middle downwards
        if(sortedCollection[middleItem] > target)
        {
            // end should equal old middle item
            endItem = middleItem;
            middleItem = (endItem - startItem) / 2 + startItem;
        }
        // if the current item is greater than the target, adjust middle upwards
        else if(sortedCollection[middleItem] < target)
        {
            // start should equal old middle item
            startItem = middleItem;
            middleItem = (endItem - startItem) / 2 + startItem;
        }
        else {
            isFound = true; // we found it
        }

    }

    return isFound;

}


// This function will find if a number is in the collection.
// It assumes the collection is sorted (in Ascending order).
// repeatedly search the smaller part in the vector
bool isTargetPresentRecursive(int target,  vector<int> &sortedCollection, int startIndex, int endIndex) {

    functionCount++;

    cout << "Recursion running " << functionCount << " times." << endl;

    //TODO: Must implement remainder of this recursive function
    bool isFound = false;
    int middleItem;


    if(startIndex == endIndex && sortedCollection[startIndex]!=target) {
        functionCount = 0;
        return false;
    }

    middleItem = (startIndex + endIndex) /2;

    if(sortedCollection[middleItem] == target) {
        isFound = true;

    }else if (sortedCollection[middleItem] > target) {
        return isTargetPresentRecursive(target, sortedCollection, startIndex, middleItem -1);

    }
    else {
        return isTargetPresentRecursive(target, sortedCollection, middleItem +1 , endIndex);
    }

    functionCount = 0;
    return isFound;


}
