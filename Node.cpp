#include <iostream>
#include "Node.h"
using namespace std;

NODE::NODE(int x) {
    data = x;
    next = nullptr;
    cout << "adding " << x << endl;
}

NODE::~NODE() {}

NODE* NODE::move_next() {
    return next;
}

void NODE::show_node() {
  
}

void NODE::insert(NODE*& x) {
    x->next = this;
}
