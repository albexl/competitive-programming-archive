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

        string a = "", b = "";

        for (int i = 0; i < n; i++)
        {
            if (i < n / 2)
                a += s[i];
            else
                b += s[i];
        }

        cout << (a == b ? "YES" : "NO") << endl;
    }

    return 0;
}