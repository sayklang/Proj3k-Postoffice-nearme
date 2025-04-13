#ifndef NODE_H
#define NODE_H

class NODE {
protected:
    int data;
    NODE* next;

public:
    NODE(int);
    virtual void show_node();
    void insert(NODE*&);
    NODE* move_next();
    virtual ~NODE();
};

#endif
