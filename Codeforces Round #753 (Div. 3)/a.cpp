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
        string keyboard;
        string s;
        cin >> keyboard >> s;

        int ans = 0, prv = -1;
        for (auto &c : s)
        {
            for (int i = 0; i < 26; i++)
            {
                if (keyboard[i] == c)
                {
                    if (prv != -1)
                    {
                        ans += abs(prv - i);
                    }
                    prv = i;
                    break;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}