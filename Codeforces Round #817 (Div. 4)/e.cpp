#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e3 + 5;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<vector<ll>> a(maxn, vector<ll>(maxn));
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x][y] += 1ll * x * y;
        }

        for (int i = 1; i < maxn; i++)
            for (int j = 1; j < maxn; j++)
                a[i][j] += a[i][j - 1];

        while (q--)
        {
            int xo, yo, xi, yi;
            cin >> xo >> yo >> xi >> yi;
            ll ans = 0;
            for (int i = xo + 1; i < xi; i++)
                ans += a[i][yi - 1] - a[i][yo];
            cout << ans << endl;
        }
    }

    return 0;
}