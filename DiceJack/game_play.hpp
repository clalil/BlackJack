//
//  game_play.hpp
//  DiceJack
//
//  Created by Clarissa Liljander on 2020-11-13.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
#pragma once
#include <vector>

void InvalidInput(int user_input);
void CompRolled(std::vector<int> dices);
std::vector<int> GenerateCardDeck();
int RandomCard(const std::vector<int> deck);
bool CurrentTotal(std::vector<int> dices, int player_total);
int CompTurn(int player_total);
int WhoWon(int player_total, int credits, int bet);
int PlayRound(int& credits);
bool IsGameOver(bool& gameover);
