#include "AutoResizable.h"
#include "Printable.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main(void) {
    cout << "TESTING VECTOR:" << endl;

    cout << "Testing empty constructor:" << endl;
    Vector *v1 = new Vector();
    cout << "Should have size 3. Size of v = " << v1->getCurrSize() << endl;
    v1->print();
    delete v1;
    v1 = NULL;
    cout << endl;

    cout << "Testing constructor with size input:" << endl;
    Vector *v2 = new Vector(4);
    cout << "Should have size 4. Size of v = " << v2->getCurrSize() << endl;
    v2->print();
    delete v2;
    v2 = NULL;
    cout << endl;

    cout << "Testing constructor with array input:" << endl;
    int *vector_values = new int[4];
    vector_values[0] = 7;
    vector_values[1] = 8;
    vector_values[2] = 9;
    vector_values[3] = -1;
    Vector *v3 = new Vector(vector_values);
    cout << "Should have size 3. Size of v = " << v3->getCurrSize() << endl;
    v3->print();
    cout << endl;

    cout << "Testing Vector Sum function:" << endl;
    v3->print();
    cout << "Sum of the above vector is: " << v3->sum() << endl;
    cout << endl;

    cout << "Testing Vector Add function:" << endl;
    Vector *v4 = new Vector(vector_values);
    v3->print();
    v4->print();
    cout << "Adding the two vectors above:" << endl;
    Vector *v5 = v3->add(v4);
    v5->print();
    cout << endl;

    cout << "Testing Vector Dot function (vector input):" << endl;
    v3->print();
    v4->print();
    cout << "Dot product of the above two vectors: " << v3->dot(v4) << endl;
    Vector* v0 = new Vector(1);
    cout << "Dot product of two vectors with different dimensions: " << v3->dot(v0) << endl;
    cout << endl;

    cout << "Testing Vector Dot function (scalar input):" << endl;
    v3->print();
    cout << "Dot product of the above vector with the scalar 5: " << endl;
    Vector *v6 = v3->dot(5);
    v6->print();
    cout << endl;

    cout << "Testing Vector Cross function:" << endl;
    v3->print();
    v4->print();
    cout << "Cross product of the above vectors: " << endl;
    Vector *v7 = v3->cross(v4);
    v7->print();
    cout << "Cross product of two different vectors: " << endl;
    vector_values[0] = 3;
    vector_values[1] = 1;
    vector_values[2] = 5;
    Vector *v8 = new Vector(vector_values);
    v3->print();
    v8->print();
    cout << "Cross product is: " << endl;
    Vector *v9 = v3->cross(v8);
    v9->print();
    cout << endl;

    cout << "Testing Operator Overloads:" << endl;
    cout << "v3: ";
    v3->print();
    cout << endl;
    cout << "v4: ";
    v4->print();
    cout << endl;

    cout << "v3 + v4: ";
    Vector *v10 = v3->operator+(v4);
    v10->print();
    cout << endl;

    cout << "v3 - v4: ";
    Vector *v11 = v3->operator-(v4);
    v11->print();
    cout << endl;

    cout << "v3 * v4: " << v3->operator*(v4) << endl;

    cout << "v3 * 8: ";
    Vector *v13 = v3->operator*(8);
    v13->print();
    cout << endl;

    cout << "v3 ^ v4: ";
    Vector *v14 = v3->operator^(v4);
    v14->print();
    cout << endl;

    int v_one = v3->operator[](1);
    cout << "v3[1]: " << v_one << endl;

    delete v3;
    delete v4;
    delete v5;
    delete v6;
    delete v7;
    delete v8;
    delete v9;
    delete v10;
    delete v11;
    delete v13;
    delete v14;
    delete[] vector_values;
    v3 = NULL;
    v4 = NULL;
    v5 = NULL;
    v6 = NULL;
    v7 = NULL;
    v8 = NULL;
    v9 = NULL;
    v10 = NULL;
    v11 = NULL;
    v13 = NULL;
    v14 = NULL;
    vector_values = NULL;

    return 0;
}
