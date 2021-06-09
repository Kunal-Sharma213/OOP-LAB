#include <iostream>
using namespace std;
typedef long long ll;
void solve(ll &a, ll &b)
{
    ll temp = a;
    a = b;
    b = temp;
}
int main()
{
    ll a, b;
    ll t, i = 1;
    cout << "ENTER NUMBER OF TEST CASES\n";
    while (true)
    {
        if (cin >> t)
        {
            while (t--)
            {
                cout << "TEST CASE -> " << i++ << "\n";
                cout << "ENTER TWO INTEGERS\n";
                while (true)
                {
                    if (cin >> a >> b && (a < 0 || a > 0 || b < 0 || b > 0))
                    {
                        // (a < 0 || a > 0 || b < 0 || b > 0) -> this is written to check for floating values
                        cout << "BEFORE SWAPPING A -> " << a << "\tB -> " << b << "\n";
                        solve(a, b);
                        cout << "AFTER SWAPPING A -> " << a << "\tB -> " << b << "\n";
                        cout << "-------------------------------------\n";
                        break;
                    }

                    else
                    {
                        cout << "INVALID INPUT TRY AGAIN!!\n";
                        cin.clear();
                        while (cin.get() != '\n')
                            ;
                    }
                }
            }
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