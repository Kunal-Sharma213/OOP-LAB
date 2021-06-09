#include <bits/stdc++.h>
using namespace std;
int main()
{
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "ENTER 1 FOR SINX\nENTER 2 FOR COSX\nENTER 3 FOR 1 + (1/2)^2 + (1/3)^3... SUM\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "ENTER THE VALUE OF X (in radians)\n";
            double x;
            while (true)
            {
                if (cin >> x)
                {
                    double realAns = sin(x);
                    cout << "REAL ANSWER -> " << realAns << "\n";
                    double myAns = x;
                    double sinx = x;
                    float myAccuracy = 0.000001;
                    int i = 1;
                    double den;
                    do
                    {
                        den = 2 * i * (2 * i + 1);
                        myAns = -myAns * x * x / den;
                        sinx += myAns;
                        i++;
                    } while (myAccuracy <= fabs(realAns - sinx));
                    cout << "CALCULATED ANSWER -> " << sinx << "\n";
                    cout << "-------------------------------------\n";

                    break;
                }
                else
                {
                    cout << "INVALID INPUT TRY AGAIN!!\n";
                    cin.clear();              // to clear error flag
                    while (cin.get() != '\n') // validates until enter is entered
                        ;
                }
            }
        }
        break;
        case 2:
        {
            cout << "ENTER THE VALUE OF X (in radians)\n";
            double x;
            while (true)
            {
                if (cin >> x)
                {
                    double realAns = cos(x);
                    cout << "REAL ANSWER -> " << realAns << "\n";
                    double myAns = 1;
                    double cosx = 1;
                    double myAccuracy = 0.000001;
                    int i = 1;
                    double den;
                    do
                    {
                        den = 2 * i * (2 * i - 1);
                        myAns = -myAns * x * x / den;
                        cosx += myAns;
                        i++;
                    } while (myAccuracy <= fabs(realAns - cosx));
                    cout << "CALCULATED ANSWER -> " << cosx << "\n";
                    cout << "-------------------------------------\n";

                    break;
                }
                else
                {
                    cout << "INVALID INPUT TRY AGAIN!!\n";
                    cin.clear();              // to clear error flag
                    while (cin.get() != '\n') // validates until enter is entered
                        ;
                }
            }
        }
        break;
        case 3:
        {
            double sum = 0;
            cout << "ENTER NUMBER OF TERMS\n";
            int n;
            while (true)
            {
                if (cin >> n)
                {
                    for (int i = 1; i <= n; i++)
                    {
                        sum += (pow((1 / (double)i), i));
                    }

                    cout << "SUM IS -> " << fixed << setprecision(6) << sum << "\n";
                    cout << "-------------------------------------\n";

                    break;
                }
                else
                {
                    cout << "INVALID INPUT TRY AGAIN!!\n";
                    cin.clear();              // to clear error flag
                    while (cin.get() != '\n') // validates until enter is entered
                        ;
                }
            }
        }
        break;
        default:
            cout << "INVALID INPUT\n";
        }

        cout << "WANT TO CONTINUE(y/n)?\n";
        fflush(stdin);
        cin >> ch;
    }
}
