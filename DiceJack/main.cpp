//
//  main.cpp
//  DiceJack
//
//  Created by Clarissa Liljander on 2020-11-07.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
#include <chrono>
#include <random>
#include <vector>
#include <iostream>
using namespace std;

int credits = 100;
int user_input = 0;

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

void current_total(vector<int> dices, int player_total) {
    cout << "You rolled: " << dices.front() << " and " << dices.back() << "." << "\n";
    cout << "Your total is currently " << player_total << "." << "\n";
    cout << "You will go bust if you score over 21." << "\n";
    cout << "What would you like to do next?" << "\n";
    cout << "[1] Stick" << "\n";
    cout << "[2] Roll again" << "\n";
}

int random_dice(void) {
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 random_generator = mt19937(seed);
    uniform_int_distribution<int> dice_roller(1, 6);
    
    return dice_roller(random_generator);
}

void play_round() {
    int bet = 0;
    int player_total = 0;
    bool playing = true;
    vector<int> dices = {};
    
    cout << "Please place your bet (maximum 50)?" << "\n";
    cin  >> bet;

    if (bet > 50) {
        return;
    }

    while (playing) {
        for(int i = 0; i < 2; ++i) {
            dices.push_back(random_dice());
            player_total += random_dice();
        }

        if (player_total > 21) {
            cout << "You went bust!" << "\n";
            credits -= bet;
            return;
        }
        
        current_total(dices, player_total);
        cin >> user_input;

        dices.clear();
        if (user_input == 1) {
            
        } else if (user_input == 2) {
            
        }
    }
}

int main() {
    bool gameover = false;
    
    greeting();
    
    while(gameover != true && credits > 0) {
        current_credits(credits);
        cin >> user_input;
        
        if (user_input == 1) {
            play_round();
        } else if (user_input == 2) {
            gameover = true;
        }
    }
    
    std::cout << "You ended the game with " << credits << ". Goodbye." << "\n";
}
