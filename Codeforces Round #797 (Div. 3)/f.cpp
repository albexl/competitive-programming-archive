#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool same(vector<char> &v, vector<int> &cycle, string &s)
{

    for (int i = 0; i < cycle.size(); i++)
    {
        if (v[i] != s[cycle[i] - 1])
            return false;
    }

    return true;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        vector<vector<int>> cycles;
        vector<bool> flag(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (!flag[i])
            {
                vector<int> cycle;
                int j = i;
                while (!flag[j])
                {
                    flag[j] = true;
                    cycle.push_back(j);
                    j = p[j];
                }
                cycles.push_back(cycle);
            }
        }

        ll ans = 1;

        for (auto &cycle : cycles)
        {
            if (cycle.size() > 1)
            {
                ll count = 0;
                vector<char> cur;
                for (auto &x : cycle)
                    cur.push_back(s[x - 1]);
                do
                {
                    count++;
                    char last = cur.back();
                    for (int i = cur.size() - 1; i > 0; i--)
                        cur[i] = cur[i - 1];
                    cur[0] = last;
                } while (!same(cur, cycle, s));

                ans = ans * count / __gcd(ans, count);
            }
        }

        cout << ans << endl;
    }

    return 0;
}