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
        ll a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;

        x = max(x - a, 0ll);
        y = max(y - b, 0ll);

        if (x == 0 && y == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        if (c >= x + y)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}