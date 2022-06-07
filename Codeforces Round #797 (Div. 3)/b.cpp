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

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        bool ok = true;
        ll mx = -1, mz = -1;

        for (int i = 0; i < n && ok; i++)
        {
            if (a[i] == 0 && b[i] == 0)
                continue;
            if (b[i] == 0)
                mz = max(mz, a[i]);
            else
            {
                if (mx != -1 && a[i] - b[i] != mx)
                    ok = false;
                if (b[i] > a[i])
                    ok = false;
                mx = a[i] - b[i];
            }
        }

        if (mx != -1 && mz > mx)
            ok = false;

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}