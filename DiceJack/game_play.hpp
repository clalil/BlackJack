//
//  game_play.hpp
//  DiceJack
//
//  Created by Clarissa Liljander on 2020-11-13.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

void InvalidInput(int user_input);
void CompCards(std::vector<int> card_values, std::vector<std::string> card_types);
std::vector<int> GenerateCardDeck();
int RandomCard(std::vector<int> deck);
void RandomizeCards(int current_total, std::vector<int> deck, std::vector<int> card_values, std::vector<std::string> card_types);
bool CurrentTotal(std::vector<int> card_values, std::vector<std::string> card_types, int player_total);
int CompTurn(std::vector<int> deck, int player_total);
int WhoWon(std::vector<int> deck, int player_total, int credits, int bet);
int PlayRound(int& credits);
