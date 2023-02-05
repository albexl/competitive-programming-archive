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
        cin >> n;

        vector<ll> a(n);
        ll negs = 0, sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < 0)
            {
                a[i] = -a[i];
                negs++;
            }
            sum += a[i];
        }
        sort(a.begin(), a.end());
        if (negs % 2)
            sum -= 2 * a[0];
        cout << sum << endl;
    }

    return 0;
}