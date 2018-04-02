#include "ArrayList.h"
#define INDEX_OUT_OF_BOUNDS -1
using namespace std;

// Constructor
ArrayList::ArrayList(): AutoResizable() {

}

// Destructor
ArrayList::~ArrayList() {

}

int ArrayList::get(int index) {
    int negativeCurrSize = -this->currSize;

    if (index < negativeCurrSize || index > this->currSize) {
        return (int) NULL;
    }

    int *pointer = &this->inner[this->currSize + 1];

    return index < 0 ? pointer[index] : this->inner[index];
}

int ArrayList::remove(int index) {
    if (index < 0 || index > this->currSize) {
        return (int) NULL;
    }

    int valueToRemove = this->inner[index];

    // shift rest of array one index to the left:
    for (int i = index; i < this->currSize - 1; i++) {
        this->inner[i] = this->inner[i+1];
    }

    this->currSize--;

    return valueToRemove;
}

int ArrayList::indexOf(int num) {
    for (int i = 0; i < this->currSize; i++) {
        if (this->inner[i] == num) {
            return i;
        }
    }

    return INDEX_OUT_OF_BOUNDS;
}

void ArrayList::print() {
    int *curr;
    cout << "[";

    for (int i = 1; i <= this->currSize - 1; i++) {
        curr = &this->inner[i];
        cout << *curr << ", ";
    }

    cout << this->inner[this->currSize] << "]" << endl;
}
