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
        string s;
        cin >> s;
        vector<int> cnt(3);
        for (auto &c : s)
            cnt[c - 'A']++;

        if (cnt[1] == cnt[0] + cnt[2])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}