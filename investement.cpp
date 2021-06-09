#include <bits/stdc++.h>
using namespace std;
void solve()
{
    vector<int> principal, time;
    vector<float> rate, interest;
    for (int i = 0; i < 10; i++)
    {
        principal.push_back((i + 1) * 1000);
        time.push_back((i + 1));
        rate.push_back((0.1 + ((float)i / 100)));
    }
    for (int i = 0; i < 10; i++)
    {
        float res = principal[i] * (pow(1 + rate[i], time[i]));
        interest.push_back(res);
    }
    cout << "DISPLAYING THE TABLE\n";
    cout << "PRINCIPAL\tRATE\tTIME\tCOMPOUND INTEREST\n";
    for (int i = 0; i < 10; i++)
        cout << principal[i] << "\t\t" << rate[i] << "\t" << time[i] << "\t" << interest[i] << "\n";

    // cout << "ENTER PRINCIPAL, RATE AND TIME\n";
    // double p, r, n;
    // while (true)
    // {
    //     if (cin >> p && cin >> r && cin >> n && p > 0 && r > 0 && n > 0)
    //     {
    //         double v = p * (pow((1 + r), n));
    //         cout << "COMPOUND INTEREST -> " << v << "\n";
    //         cout << "-------------------------------------\n";

    //         break;
    //     }
    //     else
    //     {
    //         cout << "TRY AGAIN\n";
    //         cin.clear();              // to clear error flag
    //         while (cin.get() != '\n') // validates until enter is entered
    //             ;
    //     }
    // }
}
int main()
{
    solve();
    // int t, i = 1;
    // cout << "ENTER THE NUMBER OF TEST CASES\n";
    // while (true)
    // {
    //     if (cin >> t)
    //     {
    //         while (t--)
    //         {
    //             cout << "TEST CASE -> " << i++ << "\n";
    //             solve();
    //         }
    //         break;
    //     }
    //     else
    //     {
    //         cout << "INVALID INPUT TRY AGAIN!!\n";
    //         cin.clear();              // to clear error flag
    //         while (cin.get() != '\n') // validates until enter is entered
    //             ;
    //     }
    //}
}