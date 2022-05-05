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

    for (int cases = 1; cases <= t; cases++)
    {
        int n;
        cin >> n;

        vector<ll> f(n + 1);
        vector<int> go(n + 1), indeg(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> f[i];

        for (int i = 1, x; i <= n; i++)
        {
            cin >> go[i];
            indeg[go[i]]++;
        }

        ll ans = 0;
        vector<int> order;
        for (int i = 1; i <= n; i++)
            if (!indeg[i])
                order.push_back(i);

        do
        {
            vector<bool> seen(n + 1);
            ll sum = 0;
            for (auto s : order)
            {
                ll cur = 0;
                while (s != 0 && !seen[s])
                {
                    cur = max(cur, f[s]);
                    seen[s] = true;
                    s = go[s];
                }
                sum += cur;
            }
            ans = max(ans, sum);

        } while (next_permutation(order.begin(), order.end()));

        cout << "Case #" << cases << ": " << ans << endl;
    }

    return 0;
}