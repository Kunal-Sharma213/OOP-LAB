#include <bits/stdc++.h>
using namespace std;
int main()
{
    long count[6];
    memset(count, 0, sizeof(count));
    char ch = 'y';
    cout << "ENTER TOTAL NUMBER OF VOTES CASTED\n";
    int totalVotesCasted;
    int counter = 0;
    while (true)
    {
        if (cin >> totalVotesCasted)
        {
            cout << "ENTER THE LIST OF THE CANDIDATE NUMBER FOR WHOM VOTE IS CASTED ONE BY ONE\n";
            while (counter < totalVotesCasted)
            {
                int n;
                if (cin >> n && (n >= 1 && n <= 5))
                {
                    count[n]++;
                }
                else
                {
                    count[0]++;
                }
                counter++;
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
    cout << "-------------------------------------\n";
    cout << "SO HERE ARE THE RESULTS\n";
    long maxVotes = INT_MIN;
    vector<int> winner; // incase two or more candidates have the same maximum number of votes
    for (int i = 1; i < 6; i++)
    {
        maxVotes = maxVotes < count[i] ? count[i] : maxVotes;
        cout << count[i] << " PEOPLE VOTED FOR CANDIDATE " << i << "\n";
    }

    for (int i = 1; i < 6; i++)
    {
        if (maxVotes == count[i])
            winner.push_back(i);
    }
    cout << "-------------------------------------\n";
    cout << "CANDIDATE(s) WITH MAXIMUM VOTES -> ";
    for (auto &x : winner)
        cout << x << " ";
    cout << "\nTOTAL SPOILT BALLOTS -> " << count[0];
}