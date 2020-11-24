//
//  game_play.hpp
//  BlackJack
//
//  Created by Clarissa Liljander on 2020-11-13.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

void InvalidInput(int user_input);
int GotAce(int total, bool is_player);
void DrawCards(int current_total, std::vector<std::string> cards_drawn, bool first_round, bool is_player);
bool CurrentTotal(std::vector<std::string> cards_drawn, int player_total, bool first_round);
int CompTurn(int player_total);
int WhoWon(int player_total, int credits, int bet);
int PlayRound(int& credits);
