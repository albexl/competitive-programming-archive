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

        int n, k;
        cin >> n >> k;

        vector<ll> mice(k);
        for (int i = 0; i < k; i++)
            cin >> mice[i];

        sort(mice.rbegin(), mice.rend());
        int ans = 0;

        ll sum = 0;
        for (int i = 0; i < k && sum < mice[i]; i++)
        {
            ll cur = 1ll * n - mice[i];
            sum += cur;
            ans = i + 1;
        }

        cout << ans << "\n";
    }

    return 0;
}