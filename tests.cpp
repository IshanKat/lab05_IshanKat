#include <iostream>
#include "card.h"
#include "card_list.h"
using namespace std;

int main() {
    CardList cards;
    cards.insert(Card("s", "3"));
    cards.insert(Card("c", "5"));
    cards.insert(Card("h", "10"));
    // Card c("s", "3");
    // Card d("h", "k");
    // Card e("h", "10");
    // cards.print();
    // cout << cards.contains(c) << endl;
    // cout << cards.contains(d) << endl;
    // cards.getPredecessor(c).print();
    // cards.getSuccessor(c).print();
    // cards.getSuccessor(e).print();
    // cout << (cards.getSuccessor(e) == cards.getSuccessor(e)) << endl;
    // c = cards.getPredecessor(c);
    // cards.remove(c);
    // cards.print();

    Card foo = cards.lowestValue();
    // cout << (foo == cards.getSuccessor(cards.highestValue())) << endl;
    while (!(foo == cards.getSuccessor(cards.highestValue()))) {
        foo.print();
        foo = cards.getSuccessor(foo);
    }
}