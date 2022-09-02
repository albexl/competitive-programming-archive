#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        set<string> words;
        vector<set<string>> players(3);
        vector<int> score(3);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                string s;
                cin >> s;
                words.insert(s);
                players[i].insert(s);
            }
        }

        for (auto &word : words)
        {
            vector<int> writers;
            for (int i = 0; i < 3; i++)
            {
                if (players[i].find(word) != players[i].end())
                    writers.push_back(i);
            }

            int points = 0;
            if (writers.size() == 1)
                points = 3;
            else if (writers.size() == 2)
                points = 1;

            for (auto &player : writers)
                score[player] += points;
        }

        for (int i = 0; i < 3; i++)
            cout << score[i] << " \n"[i == 2];
    }

    return 0;
}