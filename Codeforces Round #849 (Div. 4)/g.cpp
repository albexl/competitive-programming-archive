#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, c;
        cin >> n >> c;

        vector<int> a;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            a.push_back(i + x);
        }

        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= c)
            {
                c -= a[i];
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}