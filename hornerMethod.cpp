#include <bits/stdc++.h>
using namespace std;
typedef double dd;
void solve()
{
    cout << "ENTER x , a , b, c, d\n";
    dd arr[5];
    int i;
    while (true)
    {
        for (i = 0; i < 5; i++)
        {
            if (cin >> arr[i])
                continue;
            else
            {
                cout << "INVALID INPUT TRY AGAIN\n";
                cin.clear();              // to clear error flag
                while (cin.get() != '\n') // validates until enter is entered
                    ;
                ;
                break;
            }
        }
        if (i == 5)
            break;
    }
    cout << "NORMALLY , THE ANSWER IS -> ";
    dd ans = 0;
    for (int i = 1; i < 5; i++)
    {
        ans += arr[i] * pow(arr[0], 5 - i - 1);
    }
    cout << ans << "\n";
    cout << "USING HORNER METHOD -> ";
    ans = arr[1];
    for (int i = 2; i < 5; i++)
    {
        ans = (ans * arr[0]) + arr[i];
    }
    cout << ans << "\n";
    cout << "-------------------------------------\n";
}

int main()
{
    cout << "ENTER NUMBER OF TEST CASES\n";
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
            cout << "INVALID INPUT TRY AGAIN!!\n";
            cin.clear();              // to clear error flag
            while (cin.get() != '\n') // validates until enter is entered
                ;
        }
    }
}
