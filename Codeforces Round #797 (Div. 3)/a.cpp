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
        ll n;
        cin >> n;
        vector<ll> v(3, n / 3);
        for (int i = 0; i < n % 3; i++)
            v[i]++;
        if (v[1] == v[2])
            v[1]++, v[2]--;
        if (v[0] == v[1])
            v[0]++, v[1]--;
        if (v[1] == v[2])
            v[1]++, v[2]--;
        
        sort(v.rbegin(), v.rend());

        cout << v[1] << " " << v[0] << " " << v[2] << endl;
    }

    return 0;
}