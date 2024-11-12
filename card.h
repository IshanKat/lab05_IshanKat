// card.h
// Author: Your name
// All class declarations related to defining a single card go here

#include <map>
#include <string>
#ifndef CARD_H
#define CARD_H
using namespace std;

class Card {
    private:
        string suit;
        string value;
        static map<string, int> suitOrder;
        static map<string, int> valueOrder;
    public:
        Card();
        Card(string s, string v);
        string getSuit() const;
        string getValue() const;
        void print() const;
        bool operator<(const Card &o) const;
        bool operator==(const Card &o) const;
        bool operator>(const Card &o) const;
};

#endif // CARD_H
