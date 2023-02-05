#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

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

        int x = 0, y = 0;
        bool ok = false;

        for (auto &c : s)
        {
            if (c == 'U')
                y++;
            else if (c == 'D')
                y--;
            else if (c == 'L')
                x--;
            else
                x++;
            if (x == 1 && y == 1)
                ok = true;
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}