#ifndef SERVERNODE_H
#define SERVERNODE_H

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

#endif // SERVERNODE_H