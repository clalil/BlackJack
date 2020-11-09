//
//  main.cpp
//  DiceJack
//
//  Created by Clarissa Liljander on 2020-11-07.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
#include <random>
#include <vector>        //vector
#include <iostream>
using namespace std;

// Set up our random device and number generator as globals
std::random_device randomDevice;
std::mt19937 randomGenerator = std::mt19937(randomDevice());

void greeting() {
    cout << "Welcome to Dicejack! The rules are simple:" << "\n";
    cout << "You start with 100 credits. You win the game if you get to 300 credits." << "\n";
}

void current_credits(int credits) {
    cout << "You currently have " << credits << " credits." << "\n";
    cout << "What would you like to do next?" << "\n";
    cout << "[1] Play a round." << "\n";
    cout << "[2] Leave the table." << "\n";
}

void current_total(vector<int> dice_rolled, int total) {
    cout << "I have rolled 2 six-sided dice and they came up as: " << "\n";
    cout << dice_rolled[0] << " and " << dice_rolled[1] << "." << "\n";
    cout << "Your total is currently " << total << ". You will go bust if you score over 21." << "\n";
}

// Create a random integer function that uses the global random generator
int randomInteger(int min, int max) {
    std::uniform_int_distribution<int> diceRoller(min, max);
    return diceRoller(randomGenerator);
}

int main() {
    vector<int> dice_rolled = {};
    bool gameover = false;
    int credits = 100;
    int input = 0;
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
                for(int i = 0; i < 2; ++i) {
                    total += randomInteger(1, 6);
                    dice_rolled.push_back(total);
                }
                
                current_total(dice_rolled, total);
                
                cout << "What would you like to do next?" << "\n";
                cout << "[1] Stick" << "\n";
                cout << "[2] Roll again" << "\n";
            }

        } else if (input == 2) {
            gameover = true;
        }
    }
    
    std::cout << "You ended the game with " << credits << ". Goodbye." << "\n";
}
