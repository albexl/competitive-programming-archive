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
        int n, s;
        cin >> n >> s;
        vector<int> pos(n + 5, -1);
        pos[0] = 0;
        int sum = 0, ans = -1;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            sum += x;
            if (pos[sum] == -1)
                pos[sum] = i;
            if(s <= sum)
                ans = max(ans, i - pos[sum - s]);
        }

        if (ans != -1)
            ans = n - ans;

        cout << ans << endl;
    }

    return 0;
}