#ifndef LL_H
#define LL_H
#include "Node.h"

class LL {
    NODE* hol;
    int size;

public:
    void add_node(NODE* A);
    void show_all();
    ~LL();
    LL();
};
#endif
