#include <bits/stdc++.h>

using namespace std;

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

        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }

        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (int i = 1, a, b; i < n; i++)
        {
            cin >> a >> b;
            a--, b--;
            g[a].push_back(b);
            g[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }

        set<int> leaves;
        for (int i = 0; i < n; i++)
            if (deg[i] == 1)
                leaves.insert(i);

        int ans = 0;
        while (k-- && !leaves.empty())
        {
            set<int> next_it;
            while (!leaves.empty())
            {
                ans++;
                int u = *(leaves.begin());
                leaves.erase(leaves.find(u));
                deg[u] = -1;
                for (auto &v : g[u])
                {
                    if (deg[v] >= 2)
                    {
                        deg[v]--;
                        next_it.insert(v);
                    }
                }
            }
            for (auto &u : next_it)
                if (deg[u] == 1)
                    leaves.insert(u);
        }

        cout << n - ans << endl;
    }

    return 0;
}