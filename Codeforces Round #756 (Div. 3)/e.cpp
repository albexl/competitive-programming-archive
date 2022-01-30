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

        int n, k;
        cin >> n >> k;

        vector<int> friends(k);
        vector<int> d1(n + 1, -1), d2(n + 1, -1);

        for (int i = 0; i < k; i++)
        {
            cin >> friends[i];
            d1[friends[i]] = 0;
        }

        vector<vector<int>> g(n + 1);
        for (int i = 1, a, b; i < n; i++)
        {
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        queue<int> Q;
        for (int i = 0; i < k; i++)
            Q.push(friends[i]);

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            for (auto &v : g[u])
            {
                if (d1[v] == -1)
                {
                    d1[v] = d1[u] + 1;
                    Q.push(v);
                }
            }
        }

        Q.push(1);
        d2[1] = 0;

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            for (auto &v : g[u])
            {
                if (d2[v] == -1 && d2[u] + 1 < d1[v])
                {
                    d2[v] = d2[u] + 1;
                    Q.push(v);
                }
            }
        }

        bool ok = false;
        for (int i = 2; i <= n; i++)
            if (g[i].size() == 1 && d2[i] != -1)
                ok = true;

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}