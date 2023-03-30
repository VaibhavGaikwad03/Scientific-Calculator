#ifndef SERVER_STACK_H
#define SERVER_STACK_H

#include "Server_Node_Header.h"

class Stack
{
    node *m_pFirst;
    int m_iCount;

public:
    Stack();
    ~Stack();
    int get_top();
    bool is_full();
    bool is_empty();
    int count_nodes();
    void display();
    void push(int iNo);
    int pop();
    friend ostream &operator<<(ostream &, Stack &);
};

#endif // SERVER_STACK_H