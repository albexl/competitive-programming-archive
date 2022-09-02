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
        string a, b;

        cin >> n >> a >> b;
        bool ok = true;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i] && (min(a[i], b[i]) != 'B' || max(a[i], b[i]) != 'G'))
                ok = false;
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}