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

        int ans = n;

        vector<int> ones(n + 5), zeroes(n + 5);
        for (int i = 1; i <= n; i++)
        {
            zeroes[i] += zeroes[i - 1];
            if (s[i - 1] == '0')
                zeroes[i]++;
        }
        for (int i = n; i >= 1; i--)
        {
            ones[i] += ones[i + 1];
            if (s[i - 1] == '1')
                ones[i]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (ones[i + 1] || zeroes[i - 1])
                ans--;
        }

        cout << ans << endl;
    }

    return 0;
}