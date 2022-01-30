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

        int n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        ll ans = 0;

        for (int i = 0; i < n - 2 * k; i++)
            ans += a[i];
        for (int i = n - 2 * k; i < n - k; i++)
            ans += a[i] / a[i + k];

        cout << ans << endl;
    }

    return 0;
}