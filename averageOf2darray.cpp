// Copyright (c) 2022 St. Mother Teresa HS All rights reserved.
//
// Created by: Michael Clermont
// Created on: June 2022
// This program uses a 2D array

#include <time.h>
#include <iostream>
#include <random>


template <int rows, int cols>
int averageOfNumbers(int (&passedIn2DList)[rows][cols]) {
    // this function adds up all the elements in  a 2D array

    int numbersAverage = 0;
    int lengthOfArray;

    for (size_t rowElement = 0; rowElement < rows; ++rowElement) {
        for (size_t columnElement = 0; columnElement < cols; ++columnElement)
            numbersAverage = numbersAverage +
            passedIn2DList[rowElement][columnElement];
    }
    lengthOfArray = sizeof(passedIn2DList)/sizeof(passedIn2DList[0]);
    lengthOfArray = sizeof(passedIn2DList[0])
    /sizeof(passedIn2DList[0][0]) * lengthOfArray;
    numbersAverage = numbersAverage / lengthOfArray;

    return numbersAverage;
}


int main() {
    // this function uses a 2D array

    int aSingleRandomNumber = 0;
    int average = 0;
    const int rows = 2;
    const int columns = 5;
    int a2DArray[rows][columns];


    for (int rowElement = 0; rowElement < rows; rowElement++) {
        for (int columnElement = 0; columnElement < columns; columnElement++) {
            std::random_device rseed;
            std::mt19937 rgen(rseed());
            std::uniform_int_distribution<int> idist(1, 50);
            aSingleRandomNumber = idist(rgen);
            a2DArray[rowElement][columnElement] = aSingleRandomNumber;
            std::cout << aSingleRandomNumber << ", ";
        }
        std::cout << std::endl;
    }

    average = averageOfNumbers(a2DArray);
    std::cout << "The average of all the numbers is: " << average << std::endl;
}
