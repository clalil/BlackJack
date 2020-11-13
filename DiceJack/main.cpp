//
//  main.cpp
//  DiceJack
//
//  Created by Clarissa Liljander on 2020-11-07.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
#include "game_info.hpp"
#include "game_play.hpp"
#include "globals.hpp"
#include <vector>
#include <iostream>
using namespace std;

int credits = 100;
int user_input = 0;

int main() {
    bool gameover = false;
    
    Greeting();
    
    while(gameover != true) {

        CurrentCredits(credits);

        cin >> user_input;
        
        if (user_input == 1) {
            PlayRound();
        } else if (user_input == 2) {
            gameover = true;
        } else {
            InvalidInput(user_input);
        }
        
        IsGameOver(gameover);
    }
}
