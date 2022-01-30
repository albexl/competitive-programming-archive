#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll>> a;

bool ok(ll x)
{
    bool deuce = false;
    vector<bool> suitable((int)a[0].size());
    for (int i = 0; i < a.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < a[0].size(); j++)
        {
            if (a[i][j] >= x)
            {
                count++;
                suitable[j] = true;
            }
        }

        if (count > 1)
            deuce = true;
    }

    if (!deuce && a[0].size() > 1)
        return false;

    for (auto x : suitable)
        if (!x)
            return false;

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

        int n, m;
        cin >> n >> m;

        a = vector<vector<ll>>(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        ll lo = 0, hi = 2e9, opt = 0;

        while (lo <= hi)
        {
            ll mid = (lo + hi) >> 1;
            if (ok(mid))
            {
                opt = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        cout << opt << endl;
    }

    return 0;
}