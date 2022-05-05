#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 5;

int pi[maxn], d[maxn], mx[maxn];
vector<int> g[maxn];
vector<int> path;
vector<vector<int>> ans;

void dfs(int u)
{
    if (g[u].size() == 0)
        d[u] = 1;
    for (auto &v : g[u])
    {
        dfs(v);
        d[u] = max(d[u], d[v] + 1);
    }
}

void solve(int u)
{
    path.push_back(u);
    if (g[u].size() == 0)
    {
        ans.push_back(path);
        path.clear();
        return;
    }

    int depth = -1;
    int x = -1;
    for (auto &v : g[u])
    {
        if (d[v] > depth)
        {
            depth = d[v];
            x = v;
        }
    }
    solve(x);
    for (auto &v : g[u])
    {
        if (v != x)
        {
            solve(v);
        }
    }
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
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            pi[i] = d[i] = mx[i] = 0;
            g[i].clear();
        }
        path.clear();
        ans.clear();

        for (int i = 1; i <= n; i++)
        {
            cin >> pi[i];
            if (pi[i] != i)
                g[pi[i]].push_back(i);
        }

        for (int i = 1; i <= n; i++)
            if (pi[i] == i)
                dfs(i);

        for (int i = 1; i <= n; i++)
            if (pi[i] == i)
                solve(i);

        cout << ans.size() << endl;
        for (auto &path : ans)
        {
            cout << path.size() << endl;
            for (int i = 0; i < path.size(); i++)
            {
                cout << path[i] << " \n"[i + 1 == path.size()];
            }
        }
    }

    return 0;
}