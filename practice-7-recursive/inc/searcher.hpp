#ifndef EX7_SEARCHER_HPP
#define EX7_SEARCHER_HPP

#include <iostream>
#include <vector>

using namespace std;

// current looping function to find a value in sorted collection
bool isTargetPresentLooping(int target, vector<int> &sortedCollection);

// you must implement a recursive version in the following function
bool isTargetPresentRecursive(int target, vector<int> &sortedCollection, int startIndex, int endIndex);

#endif //EX7_SEARCHER_HPP
