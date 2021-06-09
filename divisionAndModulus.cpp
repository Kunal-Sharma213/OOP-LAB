#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    cout << "ENTER NUMERATOR AND DENOMENATOR\n";
    ll n, d;
    while (true)
    {
        if (cin >> n >> d && n >= 0 && d > 0)
        {
            ll div = 0;
            ll rem = 0;
            if (n < d)
            {
                cout << "DIV - " << 0 << "\n";
                cout << "MOD - " << n << "\n";
                cout << "-------------------------------------\n";
                break;
            }
            while (n - d >= 0)
            {
                div++;
                n = n - d;
            }

            rem = n;
            cout << "DIV - " << div << "\n";
            cout << "MOD - " << rem << "\n";
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
int main()
{
    cout << "ENTER NUMBER OF TEST CASES\n";
    ll t;
    int i = 1;
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
            cout << "INVALID INPUT TRY AGAIN!!\n";
            cin.clear();              // to clear error flag
            while (cin.get() != '\n') // validates until enter is entered
                ;
        }
    }
}
