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

        int ans = n;
        int lo = 0, hi = n - 1;
        while (lo <= hi && s[lo] != s[hi])
        {
            ans -= 2;
            lo++;
            hi--;
        }

        cout << ans << endl;
    }

    return 0;
}