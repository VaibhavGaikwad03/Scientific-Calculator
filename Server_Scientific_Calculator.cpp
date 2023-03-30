#include <iostream>
#include "Server_Stack_Header.h"

class ScientificCalculator
{
    Stack *m_pStack;
    const char *m_cpInfix;
    char *m_pPostfix;

public:
    ScientificCalculator(char *pInfix);
    ~ScientificCalculator();
    // long evaluate();

private:
    bool is_space(char chSymbol);
    int is_operator(char chSymbol);
    void infix_to_postfix();
};

ScientificCalculator::ScientificCalculator(char *pInfix) : m_cpInfix(pInfix) 
{
    m_pStack = new Stack;
    m_pPostfix = NULL;
}

ScientificCalculator::~ScientificCalculator()
{
    if (m_pStack != NULL)
        delete m_pStack;
    m_pStack = NULL;
    m_cpInfix = m_pPostfix = NULL;
}

bool ScientificCalculator::is_space(char chSymbol)
{
    if (chSymbol == ' ')
        return true;
    return false;
}

int ScientificCalculator::is_operator(char chSymbol)
{
    switch (chSymbol)
    {
    case '^':
        return 3;

    case '*':
    case '/':
    case '%':
        return 2;

    case '+':
    case '-':
        return 1;

    default:
        return 0;
    }
}

void ScientificCalculator::infix_to_postfix()
{
    int iRet;
    char chChar;
    int iCounter1;
    int iCounter2 = 0;

    for (iCounter1 = 0; m_cpInfix[iCounter1] != '\0'; iCounter1++)
    {
        if(is_space(m_cpInfix[iCounter1]))
            continue;
        
        if(m_cpInfix[iCounter1] == '(')
            m_pStack->push(m_cpInfix[iCounter1]);
        
        else if(m_cpInfix[iCounter1] == ')')
        {
            while ((chChar = m_pStack->pop()) != '(')
                m_pPostfix[iCounter2++] = chChar;
        }
    }
}

int main(void)
{

    return 0;
}