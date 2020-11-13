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

void invalid_input(int& input) {
    while(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        
        cout << "That's not an option. Try again." << "\n";
    }
}

bool current_total(vector<int> dices, int player_total) {
    cout << "You rolled: " << dices.front() << " and " << dices.back() << "." << "\n";
    cout << "Your total is currently " << player_total << "." << "\n";
    cout << "You will go bust if you score over 21." << "\n";
    cout << "What would you like to do next?" << "\n";
    cout << "[1] Stick" << "\n";
    cout << "[2] Roll again" << "\n";
    
    cin >> user_input;
    invalid_input(user_input);
    
    if(user_input == 1) {
        return false;
    } else if (user_input == 2) {
        return true;
    } else {
        return false;
    }
}

int random_dice(void) {
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 random_generator = mt19937(seed);
    uniform_int_distribution<int> dice_roller(1, 6);
    
    return dice_roller(random_generator);
}

void comp_rolled(vector<int> dices) {
    cout << "Computer rolled: " << dices.front() << " and " << dices.back() << "\n";
}

int comp_turn(int player_total) {
    bool playing = true;
    int comp_total = 0;
    vector<int> dices = {};
        
    while(playing) {
        for(int i = 0; i < 2; ++i) {
            dices.push_back(random_dice());
            comp_total += dices.back();
        }
        
        if (comp_total > 21) {
            comp_rolled(dices);
            playing = false;
        } else if (comp_total > player_total && comp_total < 22) {
            comp_rolled(dices);
            playing = false;
        } else if (comp_total < player_total) {
            comp_rolled(dices);
            playing = true;
        }
    
        dices.clear();
    }
        
    return comp_total;
}

void who_won(int player_total, int& bet) {
    int comp_total =+ comp_turn(player_total);
    
    if (comp_total > 21) {
        cout << "Computer rolled a total of " << comp_total << "." << "\n";
        cout << "Computer went bust!" << "\n";
        cout << "You won!" << "\n";
        
        credits += bet;
        return;
    } else if (comp_total > player_total && comp_total < 22) {
        cout << "Computer rolled a total of " << comp_total << "." << "\n";
        cout << "Computer won!" << "\n";
        return;
    } else if (comp_total < player_total) {
        cout << "Computer rolled a total of " << comp_total << "." << "\n";
        cout << "You won!" << "\n";
        cout << "-------------------------" << "\n";
        return;
    }
}

void play_round() {
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
            dices.push_back(random_dice());
            player_total += dices.back();
        }
        
        playing = current_total(dices, player_total);

        if (player_total > 21) {
            cout << "You rolled " << player_total << " and went bust!" << "\n";
            credits -= bet;
            return;
        }
        
        if (playing == false) {
            who_won(player_total, bet);
        }

        dices.clear();
    }
}

bool is_gameover(bool& gameover) {
    if (credits == 0) {
        cout << "You lost the game with " << credits << " credits." << "\n";
        gameover = true;
    } else if (credits > 300) {
        cout << "You won the game with " << credits << " credits." << "\n";
        gameover = true;
    }
    
    return gameover;
}

int main() {
    bool gameover = false;
    
    greeting();
    
    while(gameover != true) {

        current_credits(credits);

        cin >> user_input;
        
        if (user_input == 1) {
            play_round();
        } else if (user_input == 2) {
            gameover = true;
        } else {
            invalid_input(user_input);
        }
        
        is_gameover(gameover);
    }
}
