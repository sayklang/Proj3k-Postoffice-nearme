#include <iostream>
#include "LL.h"
using namespace std;

LL::LL() {
    hol = nullptr;
    size = 0;
}

LL::~LL() {
    NODE* t;
    while (hol) {
        t = hol;
        hol = hol->move_next();
        delete t;
        size--;
    }
}

void LL::show_all() {
    NODE* t = hol;
    if (t == nullptr) {
        cout << "No nodes to display." << endl; 
    }
    for (int i = 0; i < size; i++) {
        t->show_node();
        t = t->move_next();
    }
}

void LL::add_node(NODE* A) {
    if (hol == nullptr) {
        hol = A;
    } else {
        hol->insert(A);
        hol = A;
    }
    size++;
}
