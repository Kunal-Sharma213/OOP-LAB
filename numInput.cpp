#include <iostream>
#include <conio.h>
using namespace std;
void solve()
{
    cout << "ENTER NUMBER OF DIGITS(NOT > 6)\n";
    int len;
    long num = 0;
    char sign;
    while (true)
    {
        if (cin >> len && len > 0 && len <= 6)
        {
            cout << "ENTER THE SIGN(+/-) \n";
            while (true)
            {
                if (cin >> sign && (sign == '+' || sign == '-'))
                    break;
                else
                {
                    cout << "\nINVALID INPUT TRY AGAIN\n";
                    cin.clear();              // to clear error flag
                    while (cin.get() != '\n') // validates until enter is entered
                        ;
                }
            }
            int counter = 0;
            cout << "ENTER THE NUMBER(WITHOUT SIGN)\n";
            while (counter < len)
            {
                char ch = getche();
                if (ch >= 48 && ch <= 57)
                {
                    num *= 10;
                    num += ch - '0';
                    counter++;
                }
                else
                {
                    cout << "\nINVALID INPUT TRY AGAIN\n";
                    num = 0;
                    counter = 0;
                }
            }
            break;
        }
        else
        {
            cout << "INVALID INPUT TRY AGAIN\n";
            cin.clear();              // to clear error flag
            while (cin.get() != '\n') // validates until enter is entered
                ;
        }
    }
    if (sign == '+')
        cout << "\nTHE NUMBER IS -> " << num << "\n";
    else
        cout << "\nTHE NUMBER IS -> " << (num * (-1)) << "\n";
    cout << "-------------------------------------\n";
}
int main()
{
    cout << "ENTER THE NUMBER OF TEST CASES\n";
    int t, i = 1;
    while (true)
    {
        if (cin >> t)
        {
            while (t--)
            {
                cout << "TEST CASE -> " << i++ << "\n";
                solve();
            }
            break;
        }
        else
        {
            cout << "INVALID INPUT TRY AGAIN\n";
            cin.clear();
            while (cin.get() != '\n')
                ;
        }
    }
}