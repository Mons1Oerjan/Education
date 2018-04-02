#include "AutoResizable.h"
#include "ArrayList.h"
#include <iostream>

int main(void) {
    printf("TESTING ARRAYLIST:\n");
    ArrayList *a = new ArrayList();
    printf("Successfully created an empty arraylist.\n");
    a->print();
    printf("Current number of elements: %d\n", a->getCurrSize());
    printf("Size of ArrayList: %d\n\n", a->getMaxSize());

    // test add:
    a->add(7);
    printf("Added 7 to the list:\n");
    a->print();
    printf("Getting value at index 1: %d\n", a->get(1));
    printf("Current number of elements: %d\n", a->getCurrSize());
    printf("Size of ArrayList: %d\n\n", a->getMaxSize());

    // test removal:
    printf("Removing value at index 1: %d\n", a->remove(1));
    a->print();
    printf("Current number of elements: %d\n", a->getCurrSize());
    printf("Size of ArrayList: %d\n\n", a->getMaxSize());

    // test dynamic resizing:
    printf("Adding 15 values to the ArrayList:\n");
    for (int i = 10; i < 25; i++) {
        printf("Adding %d to the list.\n", i);
        a->add(i);
        a->print();
        printf("currSize: %d\n", a->getCurrSize());
        printf("maxSize: %d\n", a->getMaxSize());
    }

    // test indexOf:
    printf("\n18 has the index: %d\n", a->indexOf(18));
    printf("12 has the index: %d\n", a->indexOf(12));
    printf("15 has the index: %d\n", a->indexOf(15));
    a->add(15);
    a->add(15);
    a->add(15);
    printf("15 has the index: %d\n\n", a->indexOf(15));

    // test removal:
    a->print();
    printf("Removing value at index 9: %d\n", a->remove(9));
    a->print();
    printf("Removing value at index 9: %d\n", a->remove(9));
    a->print();
    printf("Removing value at index 9: %d\n", a->remove(9));
    a->print();
    printf("Removing value at index 9: %d\n", a->remove(9));
    a->print();
    printf("Removing value at index 9: %d\n", a->remove(9));
    a->print();
    printf("Removing the last value: %d\n", a->remove(12));
    a->print();
    printf("Removing the last value: %d\n", a->remove(11));
    a->print();
    printf("Removing the first value: %d\n", a->remove(1));
    a->print();
    printf("Removing the first value: %d\n", a->remove(1));
    a->print();

    delete a;

    printf("\n\n\nTESTING ARRAYLIST ADVANCED INDICES:\n");
    ArrayList *arr = new ArrayList();

    for (int i = 1; i < 9; i++) {
        arr->add(i);
    }

    arr->print();

    printf("Testing out of bounds POSITIVE: %d\n", a->get(100));
    printf("Testing out of bounds NEGATIVE: %d\n", a->get(-100));

    printf("Testing positive values:\n");
    for (int i = 1; i < 9; i++) {
        printf("Getting value at index %d: %d\n", i, a->get(i));
    }

    printf("Testing negative values:\n");
    for (int i = -1; i > -9; i--) {
        printf("Getting value at index %d: %d\n", i, a->get(i));
    }

    delete arr;
    
    return 0;
}
