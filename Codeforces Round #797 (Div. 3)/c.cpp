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

        int n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        vector<ll> ans(n);
        ll prv = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > prv)
                ans[i] = b[i] - a[i];
            else
                ans[i] = b[i] - prv;
            prv = max(prv, b[i]);
        }

        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i + 1 == n];
    }

    return 0;
}