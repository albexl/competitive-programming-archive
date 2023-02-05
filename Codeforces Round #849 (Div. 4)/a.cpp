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
    string s = "codeforces";
    while (t--)
    {
        char c;
        cin >> c;

        if (s.find(c) != -1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}