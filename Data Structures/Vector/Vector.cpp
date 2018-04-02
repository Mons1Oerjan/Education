#include "Vector.h"
using namespace std;

// Constructor
Vector::Vector(): AutoResizable(), Printable() {
    // no input is specified. Create a vector with size=3
    for (int i = 0; i < 3; i++) {
        AutoResizable::add(0);
    }
}

// Constructor accepting the vector size
Vector::Vector(int size): AutoResizable(), Printable() {
    for (int i = 0; i < size; i++) {
        AutoResizable::add(0);
    }
}

// Constructor accepting an int array parameter
Vector::Vector(int *array): AutoResizable(), Printable() {
    for (int *i = &array[0]; *i != END_OF_ARRAY; i++) {
        AutoResizable::add(*i);
    }
}

// Destructor
Vector::~Vector() {

}

int Vector::operator [](int index) {
    return this->inner[index];
}

Vector* Vector::operator +(Vector* v) {
    return Vector::add(v);
}

Vector* Vector::operator -(Vector* v) {
    int size = (this->currSize > v->currSize) ? this->currSize: v->currSize;
    int *diff = new int[size+1];

    for (int i = 0; i < size; i++) {
        diff[i] = v->inner[i] - this->inner[i];
    }

    diff[size] = END_OF_ARRAY;
    Vector* v_sum = new Vector(diff);

    return v_sum;
}

int Vector::operator *(Vector* v) {
    return Vector::dot(v);
}

Vector* Vector::operator *(int scalar) {
    return Vector::dot(scalar);
}

Vector* Vector::operator ^(Vector* v) {
    return Vector::cross(v);
}

int Vector::sum() {
    int sum = 0;

    for (int i = 1; i <= this->currSize; i++) {
        sum += this->inner[i];
    }

    return sum;
}

Vector* Vector::add(Vector* v) {
    int maxSize = (this->currSize > v->currSize) ? this->currSize : v->currSize;
    int minSize = (this->currSize < v->currSize) ? this->currSize : v->currSize;
    int *sum = new int[maxSize+1];

    for (int i = 0; i < minSize; i++) {
        sum[i] = v->inner[i+1] + this->inner[i+1];
    }

    if (minSize != maxSize) {
        for (int j = minSize+1; j <= maxSize; j++) {
            sum[j] = (this->currSize > v->currSize) ? this->inner[j] : v->inner[j];
        }
    }

    sum[maxSize] = END_OF_ARRAY;
    Vector* v_sum = new Vector(sum);

    return v_sum;
}

int Vector::dot(Vector* v) {
    if (this->currSize != v->currSize) {
        cout << "Error: Can't perform dot product." << endl;
        return -1;
    }
    int dot = 0;

    for (int i = 0; i < this->currSize; i++) {
        dot += this->inner[i] * v->inner[i];
    }

    return dot;
}

Vector* Vector::dot(int scalar) {
    Vector* v_dot = new Vector(this->currSize);

    for (int i = 0; i <= v_dot->currSize; i++) {
        v_dot->inner[i] = this->inner[i] * scalar;
    }

    return v_dot;
}

Vector* Vector::cross(Vector* v) {
    if (this->currSize != 3 || v->currSize != 3) {
        cout << "Error: Can't perform cross product." << endl;
        return new Vector(0);
    }

    int *cross_array = new int[4];
    cross_array[0] = (this->inner[2] * v->inner[3]) - (this->inner[3] * v->inner[2]);
    cross_array[1] = (this->inner[3] * v->inner[1]) - (this->inner[1] * v->inner[3]);
    cross_array[2] = (this->inner[1] * v->inner[2]) - (this->inner[2] * v->inner[1]);
    cross_array[3] = END_OF_ARRAY;
    Vector* v_cross = new Vector(cross_array);

    return v_cross;
}

void Vector::print() {
    cout << "[";

    for (int i = 1; i < this->currSize; i++) {
        cout << this->inner[i] << ", ";
    }

    cout << this->inner[this->currSize] << "]" << endl;
}
