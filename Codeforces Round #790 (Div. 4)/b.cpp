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

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll ans = 0;

        sort(a.begin(), a.end());
        for(auto &x : a) {
            ans += x - a[0];
        }

        cout << ans << endl;
    }

    return 0;
}