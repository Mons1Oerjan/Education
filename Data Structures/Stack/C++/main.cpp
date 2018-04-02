#include "AutoResizable.h"
#include "Stack.h"
#include <iostream>

int main(void) {
    printf("\n\n\nTESTING STACK:\n");
    Stack *s = new Stack();
    printf("Successfully created an empty stack.\n");
    s->print();
    printf("Adding some numbers onto the stack.\n");
    s->add(7);
    s->add(7);
    s->add(7);
    s->add(7);
    s->add(7);
    s->print();
    printf("Peak: %d\n", s->peak());
    printf("Pop: %d\n", s->pop());
    s->print();
    printf("Adding more numbers onto the stack.\n");
    s->add(8);
    s->add(10);
    s->add(12);
    s->add(3);
    s->print();
    printf("Pop: %d\n", s->pop());
    s->print();
    printf("Pop: %d\n", s->pop());
    s->print();
    printf("Pop: %d\n", s->pop());
    s->print();
    printf("Pop: %d\n", s->pop());
    s->print();
    printf("Pop: %d\n", s->pop());
    s->print();
    delete s;
    return 0;
}
