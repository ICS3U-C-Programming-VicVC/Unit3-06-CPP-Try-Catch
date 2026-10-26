// Copyright (c) 2026 Victor Victor-Calixte All rights reserved.
// .
// Created by: Your Name
// Date: 09/16/26
// This program asks the user to guess a number between 0-9.
// It also supports input failures.


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

    // the try statement will make sure the code safely with invald user inputs
    try {
        // Converting the guessed number ( string ) -> ( number )
        guessedNumAsNum = std::stoi(guessedNumAsString);

        // Checking whether or not the user guess correcty.
        if (guessedNumAsNum == generatedNum) {
            // If they guessed correctly,
            // then let the user know they guessed correctly
            std::cout << "You guessed correctly!\n";
        } else {
            // Otherwise, let them know the correct number
            std::cout << "You guessed incorrectly!\n";
            std::cout << "The correct number was: " << generatedNum << "\n";
        }

        // If the try statement fails, it was likely
        // due to the input from the user being invalid
    } catch (std::invalid_argument) {
        // Tell the user about the mistake
        std::cout << "("
        << guessedNumAsString
        << ") is not a valid value. (MUST BE A NUMBER)\n";
    }

    // Dismiss the user
    std::cout << "Thanks for playing!\n";
}
