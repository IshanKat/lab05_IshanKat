// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h
#include "card.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;

map<string, int> Card::suitOrder = { {"c", 1}, {"d", 2}, {"s", 3}, {"h", 4} };
map<string, int> Card::valueOrder = {
    {"a", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, 
    {"8", 8}, {"9", 9}, {"10", 10}, {"j", 11}, {"q", 12}, {"k", 13}
};


Card::Card() : suit("0"), value("0") {
    suitOrder["c"] = 1;
    suitOrder["d"] = 2;
    suitOrder["s"] = 3;
    suitOrder["h"] = 4;
    valueOrder["a"] = 1;
    valueOrder["2"] = 2;
    valueOrder["3"] = 3;
    valueOrder["4"] = 4;
    valueOrder["5"] = 5;
    valueOrder["6"] = 6;
    valueOrder["7"] = 7;
    valueOrder["8"] = 8;
    valueOrder["9"] = 9;
    valueOrder["10"] = 10;
    valueOrder["j"] = 11;
    valueOrder["q"] = 12;
    valueOrder["k"] = 13;

}

Card::Card(string s, string v) : suit(s), value(v) {
    suitOrder["c"] = 1;
    suitOrder["d"] = 2;
    suitOrder["s"] = 3;
    suitOrder["h"] = 4;
    valueOrder["a"] = 1;
    valueOrder["2"] = 2;
    valueOrder["3"] = 3;
    valueOrder["4"] = 4;
    valueOrder["5"] = 5;
    valueOrder["6"] = 6;
    valueOrder["7"] = 7;
    valueOrder["8"] = 8;
    valueOrder["9"] = 9;
    valueOrder["10"] = 10;
    valueOrder["j"] = 11;
    valueOrder["q"] = 12;
    valueOrder["k"] = 13;
}

string Card::getSuit() const {
    return suit;
}

string Card::getValue() const {
    return value;
}

void Card::print() const {
    cout << suit << " " << value << endl;
}

bool Card::operator<(const Card &o) const {
    if (suitOrder[suit] == suitOrder[o.suit]) return (valueOrder[value] < valueOrder[o.value]);
    return (suitOrder[suit] < suitOrder[o.suit]);
}

bool Card::operator==(const Card &o) const {
    return (suit == o.suit) && (value == o.value);
}

bool Card::operator>(const Card &o) const {
    if (suitOrder[suit] == suitOrder[o.suit]) return (valueOrder[value] > valueOrder[o.value]);
    return (suitOrder[suit] > suitOrder[o.suit]);
}
