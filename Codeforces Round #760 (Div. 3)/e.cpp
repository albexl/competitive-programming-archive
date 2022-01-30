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
        vector<ll> a(n), freq(n + 1);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }

        sort(a.begin(), a.end());
        stack<ll> extra;

        ll acum = 0;
        bool mex = false;

        vector<ll> ans(n + 1, -1);
        for (int x = 0; x <= n; x++)
        {
            if (mex)
            {
                if (freq[x - 1] == 0 && extra.empty())
                    break;

                ll add = acum + freq[x];
                if (freq[x - 1] == 0)
                {
                    add += abs((x - 1) - extra.top());
                    acum += abs((x - 1) - extra.top());
                    extra.pop();
                }

                ans[x] = add;
            }
            else
            {
                ans[x] = freq[x];
                if (freq[x] == 0)
                    mex = true;
            }

            for (int i = 0; i + 1 < freq[x]; i++)
                extra.push(x);
        }

        for (int i = 0; i <= n; i++)
            cout << ans[i] << " \n"[i == n];
    }

    return 0;
}