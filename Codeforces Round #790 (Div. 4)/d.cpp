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
        int n, m;
        cin >> n >> m;

        map<ll, ll> m1, m2;
        vector<vector<ll>> a(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ll x = i - j;
                ll y = i + j;
                if (m1.find(x) == m1.end())
                    m1[x] = 0;
                if (m2.find(y) == m2.end())
                    m2[y] = 0;
                m1[x] += a[i][j];
                m2[y] += a[i][j];
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ll x = i - j;
                ll y = i + j;
                ans = max(ans, m1[x] + m2[y] - a[i][j]);
            }
        }

        cout << ans << endl;
    }

    return 0;
}