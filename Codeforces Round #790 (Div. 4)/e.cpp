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
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.rbegin(), a.rend());
        vector<ll> sum(n + 5);
        for (int i = 1; i <= n; i++)
            sum[i] += sum[i - 1] + a[i - 1];

        for (int i = 0; i < q; i++)
        {
            ll x;
            cin >> x;
            int lo = 1, hi = n, opt = -1;
            while (lo <= hi)
            {
                int mid = (lo + hi) >> 1;
                if (sum[mid] >= x)
                {
                    opt = mid;
                    hi = mid - 1;
                }
                else
                    lo = mid + 1;
            }

            cout << opt << endl;
        }
    }

    return 0;
}