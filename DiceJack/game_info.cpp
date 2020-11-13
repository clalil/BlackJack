//
//  functions.cpp
//  DiceJack
//
//  Created by Clarissa Liljander on 2020-11-13.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;

void Greeting() {
    cout << "Welcome to Dicejack! The rules are simple:" << "\n";
    cout << "You start with 100 credits. You win the game if you get to 300 credits." << "\n";
}

void CurrentCredits(int credits) {
    cout << "You currently have " << credits << " credits." << "\n";
    cout << "What would you like to do next?" << "\n";
    cout << "[1] Play a round." << "\n";
    cout << "[2] Leave the table." << "\n";
}

bool IsGameOver(bool& gameover, int credits) {
    if (credits == 0) {
        cout << "You lost the game with " << credits << " credits." << "\n";
        gameover = true;

    } else if (credits > 300) {
        cout << "You won the game with " << credits << " credits." << "\n";
        gameover = true;
    }
    
    return gameover;
}
