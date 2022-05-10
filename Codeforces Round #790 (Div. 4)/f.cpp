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
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }

        vector<int> a;
        for (auto &el : mp)
            if (el.second >= k)
                a.push_back(el.first);
        a.push_back(-1);
        a.push_back(2e9);
        sort(a.begin(), a.end());

        if (a.size() == 2)
        {
            cout << -1 << endl;
            continue;
        }

        int lo = a[1], hi = a[1];
        int l = 0, r = 0;
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i] != a[i - 1] + 1)
            {
                if (hi - lo >= r - l)
                    l = lo, r = hi;
                lo = hi = a[i];
            }
            else
            {
                hi++;
            }
        }

        cout << l << " " << r << endl;
    }

    return 0;
}