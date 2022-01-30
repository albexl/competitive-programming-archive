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
    while (t--)
    {
        string s;
        cin >> s;

        int l = s.size();

        if ((s[l - 1] - '0') % 2 == 0)
        {
            cout << 0 << endl;
            continue;
        }

        if ((s[0] - '0') % 2 == 0)
        {
            cout << 1 << endl;
            continue;
        }

        int ans = -1;
        for (int i = 1; i + 1 < l; i++)
        {
            if ((s[i] - '0') % 2 == 0)
            {
                ans = 2;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}