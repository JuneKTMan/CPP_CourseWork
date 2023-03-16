#include <iostream>
#include <vector>


#define FIBONACCI_LIMIT 10000

using namespace std;


void printFibonacci(vector<int> fibonacciNums) {

    // TODO - Print the Fibonacci Sequence and Report the Time Complexity as Indicated

    // Print sequence
    cout << "Fibonacci sequence: " ;
    for(int i:fibonacciNums)
        std::cout << i << " ";

    cout  << std::endl;

    // Print complexity
    cout << "Time complexity of print operation: O(N)" << std::endl;
}


void printHighestFibonacci(vector<int> fibonacciNums) {

    // TODO - Print the Highest Fibonacci number and Report the Time Complexity as Indicated

    // Print the highest Fibonacci number
    int highestFibonacci = fibonacciNums[0]; // Set the highest Fibonacci;
    for(int i = 1; i < fibonacciNums.size(); i++)  //Iterating the second Fibonacci
    {

        if(fibonacciNums[i] > highestFibonacci)
        {
            highestFibonacci = fibonacciNums[i];
        }
    }
    //Comment
    // Find the last element in the vector will be way faster
    //Constant time O(1) because vector is sorted.
    //highestFound = fibonacciNums[fibonacciNums.size() - 1];

    cout<< "Highest Fibonacci number: "<< highestFibonacci << std::endl;

    // Print complexity
    cout << "Time complexity of find highest operation: O(1)" << endl;
}


void printAverageFibonacci(vector<int> fibonacciNums) {

    // TODO - Print the Average of the Fibonacci Sequence and Report the Time Complexity as Indicated

    // Calculate and Print the Average of the Fibonacci numbers
    double avg;
    for(int i:fibonacciNums) {
        //sum += fibonacciNums[i];
        double sum = sum + i;
        avg = sum/fibonacciNums.size();

    }

    //int sum = 0;
    // float average;
    //

    cout<< "Average of Fibonacci numbers: "<< avg << std::endl;

    // Print complexity
    cout << "Time complexity of find average operation: O(N)" << std::endl;
}



int main() {

    int previousFibonacciNumber, currentFibonacciNumber = 0;

    // we will populate this vector with the Fibonnaci sequence up to the FIBONACCI_LIMIT
    // Reminder - Fibonacci sequence - 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
    vector<int> fibonacciCollection;

    // We will populate our target vector with Fibonacci numbers starting at 0 and going up to
    // the FIBONACCI_LIMIT
    fibonacciCollection.push_back(currentFibonacciNumber);
    currentFibonacciNumber = 1;
    previousFibonacciNumber = 0;

    while(currentFibonacciNumber < FIBONACCI_LIMIT) {
        fibonacciCollection.push_back(currentFibonacciNumber);

        int temp = previousFibonacciNumber + currentFibonacciNumber;
        previousFibonacciNumber = currentFibonacciNumber;
        currentFibonacciNumber = temp;
    }

    // PART 1 - Print the Fibonacci Sequence
    printFibonacci(fibonacciCollection);
    cout << endl;

    // PART 2 - Find the Highest Fibonacci Number
    printHighestFibonacci(fibonacciCollection);
    cout << endl;

    // PART 2 - Find the Average of the Fibonacci Numbers
    printAverageFibonacci(fibonacciCollection);
    cout << endl;


    return 0;
}
