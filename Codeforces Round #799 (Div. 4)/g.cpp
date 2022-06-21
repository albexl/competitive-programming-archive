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
        vector<ll> a(n + 5);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        int ans = 0;
        int b = 0;

        for (int i = 2; i <= k + 1; i++)
        {
            if (a[i - 1] < a[i] * 2)
                b++;
            else
                b--;
        }

        if (b == k)
            ans++;

        // cout << b << " " << ans << endl;

        for (int i = 2; i + k <= n; i++)
        {
            if (a[i - 1] < a[i] * 2)
                b--;
            else
                b++;

            if (a[i + k - 1] < a[i + k] * 2)
                b++;
            else
                b--;
            
            if(b == k)
                ans++;
        }

        cout << ans << endl;
    }

    return 0;
}