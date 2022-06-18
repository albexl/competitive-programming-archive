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
        vector<pii> a(4);
        for(int i = 0, x; i < 4; i++){
            cin >> x;
            a[i] = {x, i};
        }

        sort(a.rbegin(), a.rend());
        int ans = -1;
        for(int i = 0; i < 4; i++)
            if(a[i].second == 0) ans = i;
        
        cout << ans << endl;

    }

    return 0;
}