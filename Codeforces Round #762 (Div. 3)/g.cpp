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

        string s;
        cin >> s;

        int n = s.size();
        vector<int> odd(n + 1), even(n + 1);
        for (int i = 1; i <= n; i++)
        {
            odd[i] += odd[i - 1];
            even[i] += even[i - 1];
            if (s[i - 1] == '[' || s[i - 1] == ']')
            {
                if (i % 2)
                    odd[i]++;
                else
                    even[i]++;
            }
        }

        int q;
        cin >> q;

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int o = odd[r] - odd[l - 1];
            int e = even[r] - even[l - 1];
            cout << abs(o - e) << "\n";
        }
    }

    return 0;
}