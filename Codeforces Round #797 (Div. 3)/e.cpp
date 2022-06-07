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

        ll ans = 0;
        multiset<ll> S;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            ans += x / (ll)k;
            S.insert(x % k);
        }

        while (!S.empty())
        {
            ll mx = *(S.rbegin());
            S.erase(S.find(mx));

            ll smx = *(S.rbegin());
            if (mx + smx < k)
                break;

            auto it = S.lower_bound(k - mx);
            S.erase(S.find(*it));

            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
/*
1
10 10
38 195 310 313 350 474 523 686 805 972
*/