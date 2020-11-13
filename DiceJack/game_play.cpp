//
//  game_play.cpp
//  DiceJack
//
//  Created by Clarissa Liljander on 2020-11-13.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
#include "globals.hpp"
#include <chrono>
#include <random>
#include <vector>
#include <iostream>
using namespace std;

void InvalidInput(int input) {
    while(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        
        cout << "That's not an option. Try again." << "\n";
    }
}

void CompRolled(vector<int> dices) {
    cout << "Computer rolled: " << dices.front() << " and " << dices.back() << "\n";
}

int RandomDice(void) {
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 random_generator = mt19937(seed);
    uniform_int_distribution<int> dice_roller(1, 6);
    
    return dice_roller(random_generator);
}

bool CurrentTotal(vector<int> dices, int player_total) {
    cout << "You rolled: " << dices.front() << " and " << dices.back() << "." << "\n";
    
    if(player_total < 21) {
        cout << "Your total is currently " << player_total << "." << "\n";
        cout << "You will go bust if you score over 21." << "\n";
        cout << "What would you like to do next?" << "\n";
        cout << "[1] Stick" << "\n";
        cout << "[2] Roll again" << "\n";
        
        cin >> user_input;
        InvalidInput(user_input);
        
        if(user_input == 1) {
            return false;
        } else if (user_input == 2) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int CompTurn(int player_total) {
    bool playing = true;
    int comp_total = 0;
    vector<int> dices = {};
        
    while(playing) {

        for(int i = 0; i < 2; ++i) {
            dices.push_back(RandomDice());
            comp_total += dices.back();
        }
        
        if (comp_total > 21) {
            CompRolled(dices);
            playing = false;

        } else if (comp_total > player_total && comp_total < 22) {
            CompRolled(dices);
            playing = false;

        } else if (comp_total < player_total) {
            CompRolled(dices);
            playing = true;
        }
    
        dices.clear();
    }
        
    return comp_total;
}

int WhoWon(int player_total, int& credits, int bet) {
    int comp_total =+ CompTurn(player_total);
    
    if (comp_total > 21) {
        cout << "Computer rolled a total of " << comp_total << "." << "\n";
        cout << "Computer went bust!" << "\n";
        cout << "You won!" << "\n";
        
        credits += bet;

    } else if (comp_total > player_total && comp_total < 22) {
        cout << "Computer rolled a total of " << comp_total << "." << "\n";
        cout << "Computer won!" << "\n";
        
        credits -= bet;

    } else if (comp_total < player_total) {
        cout << "Computer rolled a total of " << comp_total << "." << "\n";
        cout << "You won!" << "\n";
        cout << "-------------------------" << "\n";
    }
    
    return 0;
}

int PlayRound(int& credits) {
    int bet = 0;
    int player_total = 0;
    bool playing = true;
    vector<int> dices = {};
    
    cout << "Please place your bet (maximum 50)?" << "\n";
    cin >> bet;

    while (cin.fail() || (bet > 50 || bet > credits)) {
        cin.clear();
        cin.ignore(10000, '\n');
        
        cout << "That's not a valid bet. Try again." << "\n";
        cin >> bet;
    }
    
    cout << "Let's play!" << "\n";
    cout << "-------------------------" << "\n";

    while (playing) {

        for(int i = 0; i < 2; ++i) {
            dices.push_back(RandomDice());
            player_total += dices.back();
        }
        
        playing = CurrentTotal(dices, player_total);
        
        if (player_total > 21) {
            cout << "You rolled " << player_total << " and went bust!" << "\n";
            credits -= bet;
        }
        
        if (playing == false && player_total < 21) {
            WhoWon(player_total, credits, bet);
        }

        dices.clear();
    }
    
    return 0;
}

bool IsGameOver(bool& gameover) {
    if (credits == 0) {
        cout << "You lost the game with " << credits << " credits." << "\n";
        gameover = true;

    } else if (credits > 300) {
        cout << "You won the game with " << credits << " credits." << "\n";
        gameover = true;
    }
    
    return gameover;
}
