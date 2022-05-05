#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl '\n'

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;

        cin >> n >> s;

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x = 0, y = 0, cur = 0;
            for (int j = 0; j <= i; j++)
            {

                if (s[j] == '+')
                {
                    x++;
                    y += cur / 2;
                    cur = 0;
                }
                else
                {
                    cur++;
                }

                cout << j << " " << i << ": " << x << " " << y << " " << cur << endl;

                if ((x - y - cur / 2) % 3 == 0)
                    ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}