// card_list.cpp
// Author: Your name
// Implementation of the classes defined in card_list.h

#include "card_list.h"
#include "card.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
CardList::CardList() { 
    root = nullptr;
}

// destructor deletes all nodes
CardList::~CardList() {
    clear(root);
}

// recursive helper for destructor
void CardList::clear(Node *n) {
    if (n == nullptr) {
        return;
    }
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
bool CardList::insert(Card value) {
    // return false; // REPLACE THIS NON-SOLUTION
    if (root == nullptr) {
        root = new Node(value);
        return true;
    }
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool CardList::insert(Card value, Node *n) {
    // return false; // REPLACE THIS NON-SOLUTION
    if (n->info == value)  {
        return false;
    } else if (n->info < value) {
        if (n->right == nullptr) {
            Node *a = new Node(value);
            n->right = a;
            a->parent = n;
            return true;
        } else {
            insert(value, n->right);
        }
    } else {
        if (n->left == nullptr) {
            Node *a = new Node(value);
            n->left = a;
            a->parent = n;
            return true;
        } else {
            insert(value, n->left);
        }
    }
    return false;
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
CardList::Node* CardList::getNodeFor(Card value, Node* n) const{
    // return NULL; // REPLACE THIS NON-SOLUTION
    if (n == nullptr) return NULL;
    if (n->info > value) {
        return getNodeFor(value, n->left);
    } else if (n->info < value) {
        return getNodeFor(value, n->right);
    } else {
        return n;
    }
}

void CardList::print() const {
    print(root);
}

void CardList::print(Node *n) const {
    if (n == nullptr) return;
    print(n->left);
    n->info.print();
    print(n->right);
}

// returns true if value is in the tree; false if not
bool CardList::contains(Card value) const {
    // return false; // REPLACE THIS NON-SOLUTION
    Node *curr = root;
    if (curr == nullptr) return false;
    while (curr) {
        if (curr == nullptr) return false;
        // cout << curr->info << " " << value << endl;
        if (curr->info > value) {
            curr = curr->left;
        } else if (curr->info < value) {
            curr = curr->right;
        } else {
            return true;
        }
    }
    return false;
}

// returns the Node containing the predecessor of the given value
// go to the left node then go as far right from there as possible
CardList::Node* CardList::getPredecessorNode(Card value) const{
    // return NULL; // REPLACE THIS NON-SOLUTION
    Node *n;
    n = getNodeFor(value, root);
    if (!n) return NULL; // value doesn't exist in tree
    if (!n->left) {
        while (n->parent && n->parent->left == n) {
            n = n->parent;
        }
        return n->parent;
    }
    
    n = n->left;
    while (n->right) {
        n = n->right;
    }
    return n;
}

// returns the predecessor value of the given value or 0 if there is none
Card CardList::getPredecessor(Card value) const{
    // return -1; // REPLACE THIS NON-SOLUTION
    Node *n = getPredecessorNode(value);
    if (!n) return Card();
    return n->info;
}

// returns the Node containing the successor of the given value
CardList::Node* CardList::getSuccessorNode(Card value) const{
    // return NULL; // REPLACE THIS NON-SOLUTION
    Node *n;
    n = getNodeFor(value, root);
    if (!n) return NULL; // value doesn't exist in tree
    if (!n->right) {
        while (n->parent && n->parent->right == n) {
            n = n->parent;
        }
        return n->parent;
    }
    
    n = n->right;
    while (n->left) {
        n = n->left;
    }
    return n;
}

Card CardList::getSuccessor(Card value) const{
    // return -1; // REPLACE THIS NON-SOLUTION
    Node *n = getSuccessorNode(value);
    if (!n) return Card();
    return n->info;
}

Card CardList::lowestValue() const {
    Node *curr = root;
    while (curr->left) {
        curr = curr->left;
    }
    return curr->info;
}

Card CardList::highestValue() const {
    Node *curr = root;
    while (curr->right) {
        curr = curr->right;
    }
    return curr->info;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool CardList::remove(Card value){
    // return false; // REPLACE THIS NON-SOLUTION
    Node *n;
    n = getNodeFor(value, root);
    if (!n) return false;
    if (!n->left && !n->right) {
        if (!n->parent) {
            delete root;
            root = nullptr;
        } else {
            if (n->parent->left == n) n->parent->left = nullptr;
            if (n->parent->right == n) n->parent->right = nullptr;
            delete n;
        }
    } else if (!n->left) {
        if (!n->parent) {
            root = n->right;
            n->right->parent = nullptr;
        } else if (n->parent->left == n) {
            n->right->parent = n->parent;
            n->parent->left = n->right;
        } else {
            n->right->parent = n->parent;
            n->parent->right = n->right;
        }
        delete n;
    } else if (!n->right) {
        if (!n->parent) {
            root = n->left;
            n->left->parent = nullptr;
        } else if (n->parent->left == n) {
            n->left->parent = n->parent;
            n->parent->left = n->left;
        } else {
            n->left->parent = n->parent;
            n->parent->right = n->left;
        }
        delete n;
    } else {
        Node *replacement = getSuccessorNode(n->info);
        Card tmp = replacement->info;
        remove(tmp);
        n->info = tmp;
    }
    return true;
}