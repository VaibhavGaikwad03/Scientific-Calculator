#ifndef SERVER_NODE_H
#define SERVER_NODE_H

#include <iostream>
using std::ostream;

class Stack;

class node
{
    int m_iData;
    node *m_pNext;

public:
    node();
    ~node();

    friend class Stack;
    friend ostream &operator<<(ostream &, Stack &);
};

#endif // SERVER_NODE_H