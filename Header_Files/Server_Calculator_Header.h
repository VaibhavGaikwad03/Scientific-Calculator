#ifndef CALCULATOR_HEADER_H
#define CALCULATOR_HEADER_H

#include "Server_Stack_Header.h"
#define MAX 50
 
class ScientificCalculator
{
    Stack *m_pStack;
    const char *m_cpInfix;
    char m_pPostfix[MAX];

public:
    ScientificCalculator(const char *pInfix = NULL);
    ~ScientificCalculator();
    long evaluate(const char *cpInfix = NULL);

private:
    void infix_to_postfix();
    bool is_space(char chSymbol);
    int is_operator(char chSymbol);
};

#endif //CALCULATOR_HEADER_H 
