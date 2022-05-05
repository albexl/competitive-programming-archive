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
        vector<vector<ll>> a(3, vector<ll>(4));
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                cin >> a[i][j];

        vector<ll> cap(4);
        for (int i = 0; i < 4; i++)
            cap[i] = min({a[0][i], a[1][i], a[2][i]});

        ll sum = cap[0] + cap[1] + cap[2] + cap[3];
        ll dif = sum - 1000000;

        cout << "Case #" << cases << ":";
        if (dif < 0)
            cout << " IMPOSSIBLE" << endl;
        else
        {
            for (int i = 0; i < 4; i++)
            {
                ll mn = min(cap[i], dif);
                cap[i] -= mn;
                dif -= mn;
            }

            for (int i = 0; i < 4; i++)
                cout << " " << cap[i];
            cout << endl;
        }
    }

    return 0;
}