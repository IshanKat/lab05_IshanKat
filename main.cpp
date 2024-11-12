// This file should implement the game using a custom implementation of a BST (that is based on your implementation from lab02)
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "card.h"
#include "card_list.h"
// Do not include set in this file

using namespace std;

int main(int argc, char* argv[]) {
  if(argc < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }

  ifstream cardFile1(argv[1]);
  ifstream cardFile2(argv[2]);
  string line;
  CardList acards, bcards;

  if (cardFile1.fail() || cardFile2.fail()) {
    cout << "Could not open file " << argv[2];
    return 1;
  }

  //Read each file
  while (getline(cardFile1, line) && (line.length() > 0)) {
    stringstream ss(line);
    string suit, value;
    ss >> suit >> value;
    acards.insert(Card(suit, value));
  }

  cardFile1.close();


  while (getline(cardFile2, line) && (line.length() > 0)) {
    stringstream ss(line);
    string suit, value;
    ss >> suit >> value;
    bcards.insert(Card(suit, value));
  }

  bool hasMatch = true;
  while (hasMatch) {
    hasMatch = false;
    Card c = acards.lowestValue();
    while (!(c == acards.getSuccessor(acards.highestValue()))) {
      if (bcards.contains(c)) {
        acards.remove(c);
        bcards.remove(c);
        cout << "Alice picked matching card " << c.getSuit() << " " << c.getValue() << endl;
        hasMatch = true;
        break;
      }
      c = acards.getSuccessor(c);
    }

    c = bcards.highestValue();
    while (!(c == bcards.getPredecessor(bcards.lowestValue()))) {
      if (acards.contains(c)) {
        acards.remove(c);
        bcards.remove(c);
        cout << "Bob picked matching card " << c.getSuit() << " " << c.getValue() << endl;
        hasMatch = true;
        break;
      }
      c = bcards.getPredecessor(c);
    }
  }

  cardFile2.close();

  cout << endl;
  cout << "Alice's cards: " << endl;
  acards.print();

  cout << endl;
  cout << "Bob's cards: " << endl;
  bcards.print();

  return 0;
}
