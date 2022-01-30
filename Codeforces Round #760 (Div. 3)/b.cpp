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

        n -= 2;

        vector<string> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        string ans = "";

        ans += a[0];
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1][1] == a[i][0])
                ans += a[i][1];
            else
                ans += a[i];
        }

        if (ans.size() != n + 2)
            ans += "a";

        cout << ans << endl;
    }

    return 0;
}