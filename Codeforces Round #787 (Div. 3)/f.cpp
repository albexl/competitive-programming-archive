#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> pi;
vector<vector<int>> g;
vector<bool> seen;

void dfs(int u, int p)
{
    for (auto &v : g[u])
    {
        if (v != p)
        {
            pi[v] = u;
            dfs(v, u);
        }
    }
};

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {

        int n, k, x, y;
        cin >> n >> k >> x >> y;

        g = vector<vector<int>>(n + 1);
        seen = vector<bool>(n + 1);
        pi = vector<int>(n + 1);

        set<int> s;
        for (int i = 0; i < k; i++)
        {
            int u;
            cin >> u;
            s.insert(u);
        }

        for (int i = 1, a, b; i < n; i++)
        {
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        dfs(x, 0);

        int ans = 0;

        int cur = y;
        while (y != x)
        {
            ans++;
            seen[y] = true;
            y = pi[y];
        }
        seen[x] = true;

        for (auto &u : s)
        {
            int v = u;
            while (!seen[v])
            {
                seen[v] = true;
                ans += 2;
                v = pi[v];
            }
        }

        cout << ans << endl;
    }

    return 0;
}