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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
        {
            int x;
            string s;
            cin >> x >> s;
            for (auto &c : s)
            {
                if (c == 'D')
                {
                    a[i] = (a[i] + 1) % 10;
                }
                else
                {
                    a[i] = (a[i] - 1 + 10) % 10;
                }
            }
        }

        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i + 1 == n];
    }

    return 0;
}