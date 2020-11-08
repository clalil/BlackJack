//
//  main.cpp
//  DiceJack
//
//  Created by Clarissa Liljander on 2020-11-07.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
#include <cstdlib>       // srand, rand
#include <ctime>         // time
#include <vector>        //vector
#include <iostream>
using namespace std;

void greeting() {
    std::cout <<
    "Welcome to Dicejack! Please take a seat at the table. " <<
    "You start with 100 credits. You win the game if you get to 300 credits." << "\n";
}

void current_credits(int credits) {
   cout <<
    "You have " << credits << " credits." << "\n"
    << "What would you like to do next?" << "\n"
    << "[1] Play a round." << "\n"
    << "[2] Leave the table." << "\n";
}

void roll_dice(int& total) {
    vector<int> dices = {};
    srand(time(NULL));

    for(int i = 0; i < 2; ++i) {
        int diceRoll = 1 + (rand() % 6);
        dices.push_back(diceRoll);
        total += diceRoll;
    }
    
    cout <<
    "I have rolled 2 six-sided dice and they came up "
    << dices[0] << " and " << dices[1] << "."
    << "Your total is currently " << total << ". You will go bust if you score over 21." << "\n";
}

int main() {
    bool gameover = false;
    int input = 0;
    int credits = 100;
    int bet = 0;
    int total = 0;
    
    greeting();
    
    while(gameover != true && credits > 0) {
        current_credits(credits);
        
        cin >> input;
        
        if(input == 1) {
            cout <<
            "How much would you like to bet (maximum 50)?" << "\n";
            cin >> bet;

            if(bet > 50) {
                cout << "Your bet is too high. Bet again." << "\n";
                cin >> bet;
            } else {
                roll_dice();
            }

        } else if (input == 2) {
            gameover = true;
        }
    }
    
    std::cout << "You ended the game with " << credits << ". Goodbye." << "\n";
}
