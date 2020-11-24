//
//  card_deck.hpp
//  DiceJack
//
//  Created by Clarissa Liljander on 2020-11-23.
//  Copyright © 2020 Clarissa Liljander. All rights reserved.
//
# include <string>
# include <vector>

struct Card {
    Card(const int& value, const std::string& text);
    int value;
    std::string text;
};

class CardDeck {
    std::vector<Card> cards;
    std::string CardDescription(const char suit, const std::string letters);

public:
    CardDeck();
    void ResetDeck();
    Card Draw();
};
