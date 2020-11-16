//
//  game_info.hpp
//  BlackJack
//
//  Created by Clarissa Liljander on 2020-11-13.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
#pragma once
#include <vector>

extern std::vector<int> dices;

void Greeting();
void CurrentCredits(int credits);
bool IsGameOver(bool& gameover, int credits);
