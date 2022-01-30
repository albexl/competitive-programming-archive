#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

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

        vector<ll> a(n), g(2);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            g[i % 2] = __gcd(g[i % 2], a[i]);

        ll ans = 0;
        for (int i = 0; i < 2; i++)
        {
            bool ok = true;
            for (int j = 0; j < n; j++)
            {
                if (j % 2 == i % 2)
                    ok &= (a[j] % g[i] == 0);
                else
                    ok &= (a[j] % g[i] != 0);
            }

            if (ok)
                ans = g[i];
        }

        cout << ans << endl;
    }

    return 0;
}