#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "AutoResizable.h"
#include "Printable.h"
#include <iostream>

class ArrayList: public AutoResizable, public Printable {
    public:
        ArrayList();
        ~ArrayList();
        int get(int index);
        int remove(int index);
        int indexOf(int num);
        void print();
};

#endif
