// Copyright (c) 2021 Luke Beausoleil All rights reserved
//
// Created by: Luke Beausoleil
// Created on: June 2021
// This program finds the average of ten random numbers

#include <iostream>
#include <random>

int main() {
    // this function finds the average

    // declaration
    int numbers[10];  // array
    int singleNumber;  // variable
    float total = 0;  // variable
    float average;  // variable

    // process -- generate random numbers
    std::cout << "The numbers are [ ";  // output
    for (int loopCounter = 0; loopCounter < 10; loopCounter++) {
        std::random_device rseed;
        std::mt19937 rgen(rseed());  // mersenne_twister
        std::uniform_int_distribution<int> idist(1, 100);  // [1,100]
        singleNumber = idist(rgen);
        numbers[loopCounter] = singleNumber;
        std::cout << singleNumber << " ";  // output
    }
    std::cout << "]" << std::endl;  // output

    // process -- find average
    // https://stackoverflow.com/questions/4108313/
    //     how-do-i-find-the-length-of-an-array
    for (int loopCounter = 0; loopCounter <
         (sizeof(numbers)/sizeof(*numbers)); loopCounter++) {
        total += numbers[loopCounter];
    }
    average = total / (sizeof(numbers)/sizeof(*numbers));

    // output
    std::cout << "The average is " << average << "\nDone." << std::endl;
}
