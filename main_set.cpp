// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include "card.h"

using namespace std;

int main(int argc, char* argv[]) {
  if(argc < 3) {
    cout << "Please provide 2 file names" << endl;
    return 1;
  }

  ifstream cardFile1(argv[1]);
  ifstream cardFile2(argv[2]);
  string line;
  set<Card> a, b;

  // Card c("h", "10");
  // Card d("h", "2");
  // cout << c.getSuit() << " " << c.getValue() << endl;
  // cout << d.getSuit() << " " << d.getValue() << endl;
  // cout << (c < d) << endl;

  if (cardFile1.fail() || cardFile2.fail()) {
    cout << "Could not open file " << argv[2];
    return 1;
  }

  //Read each file
  while (getline(cardFile1, line) && (line.length() > 0)) {
    stringstream ss(line);
    string suit, value;
    ss >> suit >> value;
    Card c(suit, value);
    a.insert(c);
  }

  cardFile1.close();

  while (getline(cardFile2, line) && (line.length() > 0)) {
    stringstream ss(line);
    string suit, value;
    ss >> suit >> value;
    Card c(suit, value);
    b.insert(c);
  }

  bool hasMatch = true;
  while (hasMatch) {
    hasMatch = false;
    for (auto p : a) {
      if (b.find(p) != b.end()) {
        a.erase(p);
        b.erase(p);
        cout << "Alice picked matching card " << p.getSuit() << " " << p.getValue() << endl;
        hasMatch = true;
        break;
      }
    }

    set<Card>::reverse_iterator it;
    for (it = b.rbegin(); it != b.rend(); it++) {
      if (a.find(*it) != a.end()) {
        cout << "Bob picked matching card " << it->getSuit() << " " << it->getValue() << endl;
        a.erase(*it);
        b.erase(*it);
        hasMatch = true;
        break;
      }
    }
  }

  cardFile2.close();

  cout << endl;
  cout << "Alice's cards: " << endl;
  for (auto p : a) {
    cout << p.getSuit() << " " << p.getValue() << endl;
  }

  cout << endl;
  cout << "Bob's cards: " << endl;
  for (auto p : b) {
    cout << p.getSuit() << " " << p.getValue() << endl;
  }

  return 0;
}
