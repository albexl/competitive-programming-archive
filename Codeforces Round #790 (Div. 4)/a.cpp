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

        int s1 = 0, s2 = 0;
        for (int i = 0; i < 6; i++)
        {
            if (i < 3)
                s1 += (s[i] - '0');
            else
                s2 += (s[i] - '0');
        }

        cout << (s1 == s2 ? "YES" : "NO") << endl;
    }

    return 0;
}