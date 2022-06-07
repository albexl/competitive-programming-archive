#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> g;
vector<int> b, w;
string s;

void dfs(int u)
{
    b[u] += s[u - 1] == 'B';
    w[u] += s[u - 1] == 'W';

    for (auto &v : g[u])
    {
        dfs(v);
        b[u] += b[v];
        w[u] += w[v];
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

        g = vector<vector<int>>(n + 1);
        b = vector<int>(n + 1);
        w = vector<int>(n + 1);
        for (int i = 2, x; i <= n; i++)
        {
            cin >> x;
            g[x].push_back(i);
        }

        cin >> s;

        dfs(1);

        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += (w[i] == b[i]);

        cout << ans << endl;
    }

    return 0;
}