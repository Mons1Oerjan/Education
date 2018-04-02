#ifndef VECTOR_H
#define VECTOR_H
#include "AutoResizable.h"
#include "Printable.h"
#include <iostream>
#define END_OF_ARRAY -1

class Vector: public AutoResizable, public Printable {
    public:
        Vector();
        Vector(int size);
        Vector(int* array);
        ~Vector();
        int operator [](int index);
        Vector* operator +(Vector* v);
        Vector* operator -(Vector* v);
        int operator *(Vector* v);
        Vector* operator *(int scalar);
        Vector* operator ^(Vector* v);
        int sum();
        Vector* add(Vector* v);
        int dot(Vector* v);
        Vector* dot(int scalar);
        Vector* cross(Vector* v);
        void print();
};

#endif
