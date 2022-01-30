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
        vector<ll> a(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
        }

        vector<ll> ans(3);
        for (int i = 0; i < 3; i++)
        {
            ll mx = -1;
            for (int j = 0; j < 3; j++)
            {
                if (i != j)
                {
                    mx = max(mx, a[j]);
                }
            }

            if (a[i] <= mx)
                ans[i] = mx - a[i] + 1;
        }

        for (int i = 0; i < 3; i++)
        {
            cout << ans[i] << " \n"[i == 2];
        }
    }

    return 0;
}