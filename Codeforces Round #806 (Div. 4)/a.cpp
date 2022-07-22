#include <bits/stdc++.h>

using namespace std;

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
        string s;
        cin >> s;

        string target = "yes";
        bool ok = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (tolower(s[i]) != target[i])
                ok = false;
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}