#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const ll maxn = 1e9 + 5;

    set<ll> nums;

    for (ll x = 1; x * x <= maxn; x++)
    {
        nums.insert(x * x);
        nums.insert(x * x * x);
    }

    int t;
    cin >> t;

    while (t--)
    {

        ll x;
        cin >> x;

        ll ans = 0;
        for (auto &y : nums)
            ans += (y <= x);

        cout << ans << endl;
    }

    return 0;
}