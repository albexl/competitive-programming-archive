#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<string> suffixes = {"00", "25", "50", "75"};

    while (t--)
    {
        string s;
        cin >> s;

        int ans = 1e9;

        int n = s.size();

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                bool ok = false;
                for (int k = 0; k < 4; k++)
                {
                    if (s[i] == suffixes[k][0] && s[j] == suffixes[k][1])
                        ok = true;
                }

                if (ok)
                    ans = min(ans, j - i - 1 + n - j - 1);
            }

        cout << ans << "\n";
    }

    return 0;
}