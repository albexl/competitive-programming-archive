#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<pair<pair<int, int>, int>> ans;
        vector<int> b = a;
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (a[j] == b[i])
                {
                    int shift = j - i;
                    if (shift)
                    {
                        ans.push_back({{i, j}, shift});
                    }
                }
            }
        }

        cout << ans.size() << endl;
        for (auto &el : ans)
            cout << el.first.first + 1 << " " << el.first.second + 1 << " " << el.second << endl;
    }

    return 0;
}