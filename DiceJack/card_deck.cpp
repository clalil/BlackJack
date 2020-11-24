//
//  card_deck.cpp
//  DiceJack
//
//  Created by Clarissa Liljander on 2020-11-23.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
#include "card_deck.hpp"
#include <algorithm>
#include <random>
#include <ctime>

Card::Card(const int& card_value, const std::string& card_description) {
    value = card_value;
    text = card_description;
};

CardDeck::CardDeck() {
    ResetDeck();
};

void CardDeck::ResetDeck() {
    std::vector<std::string> letters = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    cards.clear();

        for(int j = 0; j < 13; ++j) {
            int value = j + 1;

            cards.push_back(Card(value, CardDescription('H', letters[j])));
            cards.push_back(Card(value, CardDescription('C', letters[j])));
            cards.push_back(Card(value, CardDescription('S', letters[j])));
            cards.push_back(Card(value, CardDescription('D', letters[j])));
        }

    std::mt19937 randomiser = std::mt19937((unsigned int)std::time(nullptr));
    std::shuffle(cards.begin(), cards.end(), randomiser);
}

std::string CardDeck::CardDescription(const char suit, const std::string letters) {
    std::string text = suit + letters;
    return text;
}

Card CardDeck::Draw() {
    Card drawn = cards.front();
    cards.erase(cards.begin() + 1);
    cards.push_back(drawn);
    return drawn;
};


