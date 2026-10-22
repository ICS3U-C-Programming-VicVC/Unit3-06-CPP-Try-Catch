// Copyright (c) 2026 Victor Victor-Calixte All rights reserved.
// .
// Created by: Your Name
// Date: 09/16/26
// Write what this program does.


#include <string>
#include<iostream>
#include <random>


int main() {
    // Setting the necessary variables
    int generatedNum;
    int guessedNumAsNum;
    std::string guessedNumAsString;


    // Creating the needed number generator
    std::random_device rseed;
    std::mt19937 rgen(rseed());


    std::uniform_int_distribution<int> idist(0, 9);


    // Assigning a random generated number to the generatedNum variable
    generatedNum = idist(rgen);


    // Asks the user to guess a number between 0-9.
    // And assigns the input to guessedNum variable
    std::cout << "Guess a number in the range of 0-9: ";
    std::cin >> guessedNumAsString;




    try {
        guessedNumAsNum = std::stoi(guessedNumAsString);


        if (guessedNumAsNum == generatedNum) {
            std::cout << "You guessed correctly!\n";
        } else {
            std::cout << "You guessed incorrectly!\n";
            std::cout << "The correct number was: " << generatedNum << "\n";
        }
    } catch (std::invalid_argument) {
        std::cout << "("
        << guessedNumAsString
        << ") is not a valid value. (MUST BE A NUMBER)\n";
    }


    std::cout << "Thanks for playing!\n";
}
