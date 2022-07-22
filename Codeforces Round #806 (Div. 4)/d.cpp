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
        cin >> n;
        multiset<string> s;
        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            s.erase(s.find(a[i]));

            bool ok = false;
            for (int j = 0; j + 1 < a[i].size(); j++)
            {
                string pref = "", suff = "";
                for (int k = 0; k <= j; k++)
                    pref += a[i][k];
                for (int k = j + 1; k < a[i].size(); k++)
                    suff += a[i][k];
                if (s.find(pref) != s.end() && s.find(suff) != s.end())
                {
                    ok = true;
                    break;
                }
            }

            if (ok)
                ans += "1";
            else
                ans += "0";

            s.insert(a[i]);
        }

        cout << ans << endl;
    }

    return 0;
}