#ifndef STACK_H
#define STACK_H
#include "AutoResizable.h"
using namespace std;

class Stack: public AutoResizable {
    public:
        Stack();
        ~Stack();
        int peak();
        int pop();
        void print();
};

#endif
