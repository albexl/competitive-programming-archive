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

        map<int, int> mp;
        for (int i = 0, x; i < n; i++){
            cin >> x;
            mp[x]++;
        }

        int ans = 0;
        int rem = 0;
        for(auto &x : mp){
            ans++;
            rem += x.second - 1;
        }

        if(rem & 1)
            ans--;

        cout << ans << endl;

    }

    return 0;
}