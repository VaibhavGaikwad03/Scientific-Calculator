#include <cmath>
#include <cstring>
#include "Server_Calculator_Header.h"
 
ScientificCalculator::ScientificCalculator(const char *pInfix) : m_cpInfix(pInfix)
{
    m_pStack = new Stack;
    memset(m_pPostfix, 0, MAX);
}

ScientificCalculator::~ScientificCalculator()
{
    if (m_pStack != NULL)
        delete m_pStack;
    m_pStack = NULL;
    m_cpInfix = NULL;
    memset(m_pPostfix, 0, MAX);
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
        if (is_space(m_cpInfix[iCounter1]))
            continue;

        if (m_cpInfix[iCounter1] == '(')
            m_pStack->push(m_cpInfix[iCounter1]);

        else if (m_cpInfix[iCounter1] == ')')
        {
            while ((chChar = m_pStack->pop()) != '(')
                m_pPostfix[iCounter2++] = chChar;
        }
        else if ((iRet = is_operator(m_cpInfix[iCounter1])) != 0)
        {
            while (!m_pStack->is_empty() && is_operator(m_pStack->get_top()) >= iRet)
                m_pPostfix[iCounter2++] = m_pStack->pop();
            m_pStack->push(m_cpInfix[iCounter1]);
        }
        else
        {
            m_pPostfix[iCounter2++] = '[';
            while (m_cpInfix[iCounter1] >= '0' && m_cpInfix[iCounter1] <= '9')
                m_pPostfix[iCounter2++] = m_cpInfix[iCounter1++];
            m_pPostfix[iCounter2++] = ']';

            iCounter1--;
        }
    }

    while (!m_pStack->is_empty())
        m_pPostfix[iCounter2++] = m_pStack->pop();

    m_pPostfix[iCounter2] = '\0';
}

long ScientificCalculator::evaluate(const char *cpInfix)
{
    int iNo1;
    int iNo2;
    int iAns;
    int iCounter1;
    int iCounter2;
    char pTemp[10] = {0};

    if (cpInfix != NULL)
        m_cpInfix = cpInfix;

    infix_to_postfix();

    for (iCounter1 = 0; m_pPostfix[iCounter1] != '\0'; iCounter1++)
    {
        if (m_pPostfix[iCounter1] == '[')
        {
            for (iCounter2 = 0; m_pPostfix[++iCounter1] != ']'; iCounter2++)
                pTemp[iCounter2] = m_pPostfix[iCounter1];

            pTemp[iCounter2] = '\0';

            iCounter2 = atoi(pTemp);
            m_pStack->push(iCounter2);
        }
        else
        {
            iNo2 = m_pStack->pop();
            iNo1 = m_pStack->pop();

            switch (m_pPostfix[iCounter1])
            {
            case '^':
                iAns = pow(iNo1, iNo2);
                break;

            case '*':
                iAns = iNo1 * iNo2;
                break;

            case '/':
                iAns = iNo1 / iNo2;
                break;

            case '%':
                iAns = iNo1 % iNo2;
                break;

            case '+':
                iAns = iNo1 + iNo2;
                break;

            case '-':
                iAns = iNo1 - iNo2;
                break;
            }
            m_pStack->push(iAns);
        }
    }
    return m_pStack->pop();
}
