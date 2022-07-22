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
        string s;

        cin >> n >> s;

        set<char> S;
        for (auto &c : s)
            S.insert(c);

        cout << n + S.size() << endl;
    }

    return 0;
}