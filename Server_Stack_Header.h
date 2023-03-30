#ifndef SERVERSTACK_H
#define SERVERSTACK_H

#include "Server_Node_Header.h"

class Stack
{
    node *m_pFirst;
    int m_iCount;

public:
    Stack();
    ~Stack();
    void push(int iNo);
    int pop();
    bool is_full();
    bool is_empty();
    int count_nodes();
    void display();
    friend ostream &operator<<(ostream &, Stack &);
};

#endif // SERVERSTACK_H