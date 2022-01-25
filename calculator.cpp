// Copyright (c) 2022 Noah Ouellette All rights reserved.
//
// Created by: Noah Ouellette
// Created on: Jan. 24, 2022
// This program is a basic calculator that
// asks for the operator and two numbers

#include <unistd.h>
#include <math.h>
#include <iostream>
#include <iomanip>


double Calculate(char sign, float firstNumber, float secondNumber) {
    // This function calculates the operation between both chosen numbers

    double total;

    if (sign == '+') {
        total = (firstNumber + secondNumber);
    } else if (sign == '-') {
        total = (firstNumber - secondNumber);
    } else if (sign == '/') {
        total = (firstNumber / secondNumber);
    } else if (sign == '*') {
        total = (firstNumber * secondNumber);
    } else {
        total = fmod(firstNumber, secondNumber);
    } return(total);
}


int main() {
    // This gets the user input and then calls the function
    std::cout << "This program is a basic calculator. It can add, subtract, ";
    std::cout << "multiply, divide, and find the remainder of division.\n";
    std::cout << " \n";
    std::cout << " \n";

    std::string firstNumberFromUser;
    std::string secondNumberFromUser;
    float firstNumberFromUserFloat;
    float secondNumberFromUserFloat;
    char signFromUser;
    float finalAnswer;

    do {
        // Get user input for the first number
        std::cout << "Enter your first number: ";
        std::cin >> firstNumberFromUser;
        // Make sure that the input is a number

        try {
            firstNumberFromUserFloat = std::stof(firstNumberFromUser);
            // Get user input for the second number
            std::cout << "Enter your second number: ";
            std::cin >> secondNumberFromUser;
            std::cout << " \n";

            // Make sure that the input is a number
            try {
                // Get user input for base
                secondNumberFromUserFloat = std::stof(secondNumberFromUser);

                // Get user input for the operator
                std::cout << "Enter the operator that ";
                std::cout << "you'd like to use (+, -, /, *, %): ";
                std::cin >> signFromUser;
                std::cout << " \n";

                if (signFromUser == '+' || signFromUser == '-' ||
                    signFromUser == '/' || signFromUser == '*' ||
                    signFromUser == '%') {
                    // Call the function
                    finalAnswer = Calculate(signFromUser,
                                            firstNumberFromUserFloat,
                                            secondNumberFromUserFloat);
                    std::cout << firstNumberFromUser << " " << signFromUser;
                    std::cout << " " << secondNumberFromUser << " = ";
                    std::cout << finalAnswer;

                    break;
                } else {
                    std::cout << "Operator must be either +, -, /, * or %\n";
                }
            // Print error message if input is invalid
            } catch (std::invalid_argument) {
                std::cout << "Input was invalid\n";
            }
        } catch (std::invalid_argument) {
            std::cout << "Input was invalid\n";
        }
    } while (true);
}
