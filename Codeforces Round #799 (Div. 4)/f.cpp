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
        vector<int> d(10);
        for (int i = 0, x; i < n; i++)
        {
            cin >> x;
            d[x % 10]++;
        }

        bool ok = false;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k < 10; k++)
                {
                    int sum = (i + j + k) % 10;
                    vector<int> cur(10);
                    cur[i]++;
                    cur[j]++;
                    cur[k]++;
                    if (sum == 3 && d[i] >= cur[i] && d[j] >= cur[j] && d[k] >= cur[k])
                        ok = true;
                }
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}