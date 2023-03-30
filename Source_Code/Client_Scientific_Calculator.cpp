#include <iostream>
#include "Server_Calculator_Header.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
    long lResult;
    char chChoice;
    string strEquation;
    ScientificCalculator calculator;

    while (true)
    {
        fflush(stdin);
        cout << "\nPlease enter the equation you would like to solve:\n";
        getline(cin, strEquation);

        lResult = calculator.evaluate(strEquation.c_str());

        cout << "\nYour equation has been solved! The answer is: " << lResult << endl;

        cout << "\nDo you want to solve more equations? Enter 'y' for yes or 'n' for no.\n>_";
        cin >> chChoice;
        
        if(chChoice == 'y' || chChoice == 'Y')
        {
            cout << "\nOk, let's solve another equation!\n";
            continue;
        }
        break;
    }

    cout << "\nThank you for using our calculator. Goodbye!\n";

    return 0;
}