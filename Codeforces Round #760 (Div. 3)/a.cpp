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
        vector<int> a(7);
        for (int i = 0; i < 7; i++)
            cin >> a[i];

        ll x = -1;
        bool found = false;
        for (int i = 2; i < 7; i++)
        {
            if (a[i] != a[0] + a[1] || found)
            {
                x = a[i];
                break;
            }
            if (a[i] == a[0] + a[1])
                found = true;
        }

        cout << a[0] << " " << a[1] << " " << x << endl;
    }

    return 0;
}