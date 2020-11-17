//
//  game_play.cpp
//  BlackJack
//
//  Created by Clarissa Liljander on 2020-11-13.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
#include "globals.hpp"
#include <chrono>
#include <random>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void InvalidInput(int input) {
    while(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        
        cout << "That's not an option. Try again." << "\n";
    }
}

vector<int> GenerateCardDeck() {
    vector<int> card_deck;
    vector<int> cards(13);
    vector<int>::iterator iterator;
    iota (begin(cards), end(cards), 1);

    for(iterator = cards.begin(); iterator != cards.end(); iterator++) {
        card_deck.push_back(*iterator);
        card_deck.push_back(*iterator);
        card_deck.push_back(*iterator);
        card_deck.push_back(*iterator);
    }
    
    return card_deck;
}

int RandomCard(const vector<int>& deck) {
unsigned int seed = (unsigned int)chrono::system_clock::now().time_since_epoch().count();
    mt19937 random_generator = mt19937(seed);
    uniform_int_distribution<int> random_card(1, (int)deck.size() - 1);

    return random_card(random_generator);
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

void RandomizeCards(int& current_total, vector<int>& deck, vector<int>& card_values, vector<string>& card_types, bool first_round, bool is_player) {
    int iterator = first_round ? 2 : 1;

    for(int i = 0; i < iterator; ++i) {
        int card_drawn = RandomCard(deck);
        int card_value = deck[card_drawn];

        switch(card_value) {
            case 1 :
                card_types.push_back("Ace");
                card_value = GotAce(current_total, is_player);
                break;
            case 11 :
                card_types.push_back("Knight");
                break;
            case 12 :
                card_types.push_back("Queen");
                break;
            case 13 :
                card_types.push_back("King");
                break;
            default :
                string val = to_string(card_value);
                card_types.push_back(val);
                break;
        }

        card_values.push_back(card_value);
        current_total += card_values.back();

        deck.erase(deck.begin() + card_drawn);
    }
}

void CompCards(const vector<int> card_values, const vector<string> card_types, const bool first_round) {
    if (first_round) {
       cout << "The dealer drew a " << card_types.front() << " card worth " << card_values.front() << " and a " << card_types.back() << " card worth " << card_values.back() << "." << "\n";
    } else {
       cout << "The dealer drew a " << card_types.back() << " card worth " << card_values.back() << "." << "\n";
    }
}

bool CurrentTotal(const vector<int> card_values, const vector<string> card_types, const int player_total, const bool first_round) {
    if (first_round) {
       cout << "You drew a " << card_types.front() << " card worth " << card_values.front() << " and a " << card_types.back() << " card worth " << card_values.back() << "." << "\n";
    } else {
       cout << "You drew a " << card_types.back() << " card worth " << card_values.back() << "." << "\n";
    }
    
    if(player_total < 21) {
        cout << "\n";
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
    } else {
        return false;
    }
    
    return false;
}

int CompTurn(vector<int>& deck, const int player_total) {
    bool is_player = false;
    bool first_round = true;
    bool playing = true;
    int comp_total = 0;
    vector<int> card_values = {};
    vector<string> card_types = {};
        
    while(playing) {

        RandomizeCards(comp_total, deck, card_values, card_types, first_round, is_player);
        
        if (comp_total > 21) {
            CompCards(card_values, card_types, first_round);
            playing = false;

        } else if (comp_total > player_total && comp_total < 22) {
            CompCards(card_values, card_types, first_round);
            playing = false;

        } else if (comp_total == player_total && (player_total == 17 || player_total == 18 || player_total == 19 || player_total == 20 || player_total == 21)) {
            CompCards(card_values, card_types, first_round);
            playing = false;

        } else if (comp_total < player_total) {
            CompCards(card_values, card_types, first_round);
            playing = true;
        }
    
        card_values.clear();
        card_types.clear();
        first_round = false;
    }
        
    return comp_total;
}

int WhoWon(vector<int>& deck, const int player_total, int& credits, const int bet) {
    int comp_total =+ CompTurn(deck, player_total);
    
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
        vector<int> card_values = {};
        vector<string> card_types = {};
        vector<int> deck = GenerateCardDeck();
        
        RandomizeCards(player_total, deck, card_values, card_types, first_round, is_player);

        playing = CurrentTotal(card_values, card_types, player_total, first_round);

        card_values.clear();
        card_types.clear();
        first_round = false;

        if (player_total > 21) {
            cout << "You drew a total of " << player_total << " and went bust!" << "\n";
            credits -= bet;
        }
        
        if (playing == false && player_total < 21) {
            WhoWon(deck, player_total, credits, bet);
        }

    }
    
    return 0;
}
