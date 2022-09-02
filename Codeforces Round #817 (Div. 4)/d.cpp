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
        string s;
        cin >> n >> s;

        ll score = 0;
        vector<pair<ll, ll>> to_change;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                score += (ll)i;
                if (i < n / 2)
                    to_change.push_back({(ll)(n - i - 1), (ll)i});
            }
            else
            {
                score += (ll)(n - i - 1);
                if (i >= n / 2)
                    to_change.push_back({(ll)i, (ll)(n - i - 1)});
            }
        }

        sort(to_change.rbegin(), to_change.rend());
        vector<ll> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (i < to_change.size())
            {
                score += to_change[i].first;
                score -= to_change[i].second;
            }
            ans[i] = score;
        }

        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i + 1 == n];
    }

    return 0;
}