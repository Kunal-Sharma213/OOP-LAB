#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long a, b;
    cout << "ENTER TWO INTEGERS\n";
    while (true)
    {
        if (cin >> a >> b)
        {
            cout << "ADDITION GIVES -> " << (a + b) << "\n";
            cout << "-------------------------------------\n";
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
}
int main()
{
    cout << "ENTER NUMBER OF TEST CASES\n";
    int t;
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
            cout << "INVALID INPUT TRY AGAIN\n";
            cin.clear();              // to clear error flag
            while (cin.get() != '\n') // validates until enter is entered
                ;
        }
    }
}
