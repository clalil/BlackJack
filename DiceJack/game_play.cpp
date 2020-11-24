//
//  game_play.cpp
//  BlackJack
//
//  Created by Clarissa Liljander on 2020-11-13.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
#include "card_deck.hpp"
#include "globals.hpp"
#include <chrono>
#include <random>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
CardDeck deck;

void InvalidInput(int input) {
    while(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        
        cout << "That's not an option. Try again." << "\n";
    }
}

int GotAce(const int total, const bool is_player) {
    int value = 1;

    if(is_player) {
        int input = 0;
        cout << "You're about to get an Ace card. Do you wish to use this as a 1 [1] or an 11 [2]?" << "\n";
        cin >> input;

        if (input == 1) {
        } else if (input == 2) {
            value = 11;
        } else {
            value = 1;
        }
    } else {
        if (total <= 10) {
            value = 11;
        } else {
            value = 1;
        }
    }
    
    return value;
}

void DrawCards(int& current_total, vector<string>& cards_drawn, bool first_round, bool is_player) {
    int iterator = first_round ? 2 : 1;
    string current_player = is_player ? "You were dealt " : "The dealer was dealt ";

    for(int i = 0; i < iterator; ++i) {
        Card card = deck.Draw();
        int card_value = card.value;
        string card_description = card.text;
        
        if(card_value == 1) {
            card_value = GotAce(current_total, is_player);
        }
        
        cout << current_player << card_description << " worth " << card_value << "\n";

        cards_drawn.push_back(card_description);
        current_total += card_value;
    }
}

bool CurrentTotal(const vector<string> cards, const int player_total, const bool first_round) {
    if(player_total < 21) {
        cout << "Your total is currently " << player_total << "." << "\n";
        cout << "You will go bust if you score over 21." << "\n";
        cout << "What would you like to do next?" << "\n";
        cout << "[1] Stick" << "\n";
        cout << "[2] Draw" << "\n";
        
        cin >> user_input;
        InvalidInput(user_input);
        
        if(user_input == 1) {
            return false;
        } else if (user_input == 2) {
            return true;
        } else {
            return false;
        }
    }
    
    return false;
}

int CompTurn(const int player_total) {
    bool is_player = false;
    bool first_round = true;
    bool playing = true;
    int comp_total = 0;
    vector<std::string> cards_drawn = {};
        
    while(playing) {

        DrawCards(comp_total, cards_drawn, first_round, is_player);
        
        if (comp_total > 21) {
            playing = false;

        } else if (comp_total > player_total && comp_total < 22) {
            playing = false;

        } else if (comp_total == player_total && (player_total == 17 || player_total == 18 || player_total == 19 || player_total == 20 || player_total == 21)) {
            playing = false;

        } else if (comp_total < player_total) {
            playing = true;
        }
    
        cards_drawn.clear();
        first_round = false;
    }
        
    return comp_total;
}

int WhoWon(const int player_total, int& credits, const int bet) {
    int comp_total =+ CompTurn(player_total);
    
    if (comp_total > 21) {
        cout << "\n";
        cout << "The dealer drew a total of " << comp_total << "." << "\n";
        cout << "The dealer went bust!" << "\n";
        cout << "You won!" << "\n";
        cout << "-------------------------" << "\n";
        
        credits += bet;

    } else if (comp_total > player_total && comp_total < 22) {
        cout << "\n";
        cout << "The dealer drew a total of " << comp_total << "." << "\n";
        cout << "The dealer won!" << "\n";
        cout << "-------------------------" << "\n";
        
        credits -= bet;

    } else if (comp_total == player_total && (player_total == 17 || player_total == 18 || player_total == 19 || player_total == 20 || player_total == 21)) {
        cout << "\n";
        cout << "The dealer drew a total of " << comp_total << "." << "\n";
        cout << "It's a tie! Computer won!" << "\n";
        cout << "-------------------------" << "\n";
        
        credits -= bet;
        
    } else if (comp_total < player_total) {
        cout << "\n";
        cout << "The dealer drew a total of " << comp_total << "." << "\n";
        cout << "You won!" << "\n";
        cout << "-------------------------" << "\n";
        
        credits += bet;
    }
    
    return 0;
}

int PlayRound(int& credits) {
    int bet = 0;
    int player_total = 0;
    bool playing = true;
    bool first_round = true;
    bool is_player = true;
    deck.ResetDeck();

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
        vector<std::string> cards_drawn = {};
        
        DrawCards(player_total, cards_drawn, first_round, is_player);

        playing = CurrentTotal(cards_drawn, player_total, first_round);

        cards_drawn.clear();
        first_round = false;

        if (player_total > 21) {
            cout << "You drew a total of " << player_total << " and went bust!" << "\n";
            credits -= bet;
        }
        
        if (playing == false && player_total < 21) {
            WhoWon(player_total, credits, bet);
        }

    }
    
    return 0;
}
