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

        map<int, vector<int>> mp;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            mp[x].push_back(i);
        }

        int a = -1, l = -1, r = -1;
        for(auto &el : mp){
            set<pii> s;
            vector<int> sums;
            for(auto &x : el.second){
                s.insert({})

            }
            
        }


        cout << ans << endl;
    }

    return 0;
}