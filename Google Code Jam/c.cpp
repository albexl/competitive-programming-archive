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

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        ll x = 1;
        for (int i = 0; i < n; i++)
            if (a[i] >= x)
                x++;

        cout << "Case #" << cases << ": " << x - 1 << endl;
    }

    return 0;
}