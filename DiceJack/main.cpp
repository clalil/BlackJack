//
//  main.cpp
//  DiceJack
//
//  Created by Clarissa Liljander on 2020-11-07.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//

#include <iostream>

int main() {
    bool gameover = false;
    int input = 0;
    
    while(gameover != true) {
        std::cout << "Enter 1 or 2" << "\n";
        std::cin >> input;
        
        if(input == 1) {
            std::cout << "Continue";
        } else if (input == 2) {
            gameover = true;
            std::cout << "Game Over" << "\n";
        }
    }
    //return width*depth*height;
}
