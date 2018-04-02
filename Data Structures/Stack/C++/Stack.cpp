#include "Stack.h"
#include <iostream>
using namespace std;

// Constructor
Stack::Stack(): AutoResizable() {

}

// Destructor
Stack::~Stack() {

}

int Stack::peak() {
    return this->inner[this->currSize];
}

int Stack::pop() {
    int valueToPop = this->inner[this->currSize];
    this->inner[this->currSize] = 0;
    this->currSize--;

    return valueToPop;
}

void Stack::print() {
    cout << "[";
    for (int i = 0; i < this->currSize - 1; i++) {
        cout << this->inner[i] << ", ";
    }
    cout << this->inner[this->currSize] << "]" << endl;
}
