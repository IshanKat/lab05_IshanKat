// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include <iostream>
#include "card.h"

using namespace std;

class CardList {
 public:
    CardList();                   // constructor
    ~CardList();                  // destructor
    bool insert(Card value);     // insert value; return false if duplicate
    bool contains(Card value) const;  // true if value is in tree
    void print() const;

    // THESE ARE HARDER! DO THESE LAST
    Card getPredecessor(Card value) const;       // returns the predecessor value of the given value or 0 if there is none
    Card getSuccessor(Card value) const;         // returns the successor value of the given value or 0 if there is none
    bool remove(Card value);                    // deletes the Node containing the given value from the tree
    Card lowestValue() const;
    Card highestValue() const;
    

 private:
    struct Node {
        Card info;
        Node *left, *right, * parent;
        // useful constructor:
        Node(Card v) : info(v), left(0), right(0), parent(0) { }
    };

    // just one instance variable (pointer to root node):
    Node *root;

    // recursive utility functions for use by public methods above
    Node* getNodeFor(Card value, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    void clear(Node *n); // for destructor
    bool insert(Card value, Node *n); // note overloading names for simplicity
    void print(Node *n) const;

    // these should be used by getPredecessor and getSuccessor, and ONE of them should be used by remove
    Node* getSuccessorNode(Card value) const;   // returns the Node containing the successor of the given value
    Node* getPredecessorNode(Card value) const; // returns the Node containing the predecessor of the given value
};

#endif // CARD_LIST_H
