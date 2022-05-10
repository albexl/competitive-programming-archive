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

        int n, m;
        cin >> n >> m;

        vector<string> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ans = 1e9;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int cost = 0;
                for (int k = 0; k < m; k++)
                {
                    cost += abs(a[i][k] - a[j][k]);
                }
                ans = min(ans, cost);
            }
        }

        cout << ans << endl;
    }

    return 0;
}