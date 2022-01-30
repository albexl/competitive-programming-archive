#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct union_find
{
    vector<int> p;

    union_find(int n) : p(n, -1) {}

    bool join(int u, int v)
    {
        if ((u = root(u)) == (v = root(v)))
            return false;
        if (p[u] > p[v])
            swap(u, v);
        p[u] += p[v];
        p[v] = u;
        return true;
    }

    int root(int u)
    {
        return p[u] < 0 ? u : p[u] = root(p[u]);
    }
};

ll ans = 0;

void solve(vector<ll> &a, ll d)
{
    int n = a.size();
    union_find ds(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            ll cur = abs(a[i] - a[j]);
            if (cur % d == 0)
                ds.join(i, j);
        }

    for (int i = 0; i < n; i++)
        if (-ds.p[ds.root(i)] >= n / 2)
            ans = max(ans, d);
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ans = 0;
        int n;
        cin >> n;
        vector<ll> a(n);
        map<ll, int> mp;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }

        bool inf = false;

        for (auto &el : mp)
        {
            if (el.second >= n / 2)
            {
                inf = true;
            }
        }

        if (inf)
        {
            cout << -1 << endl;
            continue;
        }

        set<ll> diff;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                diff.insert(abs(a[i] - a[j]));

        set<ll> seen;

        for (auto &d : diff)
        {
            if (d == 0)
                continue;

            for (ll m = 1; m * m <= d; m++)
            {
                if (d % m == 0)
                {
                    ll x1 = m;
                    ll x2 = d / m;
                    if (seen.find(x1) == seen.end())
                    {
                        solve(a, x1);
                        seen.insert(x1);
                    }
                    if (seen.find(x2) == seen.end())
                    {
                        solve(a, x2);
                        seen.insert(x2);
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}