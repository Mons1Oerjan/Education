#include "AutoResizable.h"
#define NULL 0

// Constructor
AutoResizable::AutoResizable() {
    this->maxSize = 10;
    this->currSize = 0;
    this->inner = new int[this->maxSize];
}

// Destructor
AutoResizable::~AutoResizable(){

}

int AutoResizable::getCurrSize() {
    return this->currSize;
}

int AutoResizable::getMaxSize() {
    return this->maxSize;
}

void AutoResizable::add(int n) {
    if (this->currSize == this->maxSize) {
        // create a new array twice the size of the old array:
        int newMaxSize = this->maxSize * 2;
        int *newArray = new int[newMaxSize];

        // copy old data over to the new array:
        for (int i = 0; i < this->maxSize; i++) {
            newArray[i] = this->inner[i];
        }

        // add n to the new array:
        this->currSize++;
        newArray[this->currSize] = n;


        // delete the old array:
        delete [] this->inner;
        this->inner = NULL;

        // point to the new array:
        this->inner = newArray;
        this->maxSize = newMaxSize;
    } else {
        // no need to resize the array. Add n to the array:
        this->currSize++;
        this->inner[this->currSize] = n;
    }
}
