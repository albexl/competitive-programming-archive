#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

typedef long long ll;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int cases = 1; cases <= t; cases++)
    {
        int n, m;
        cin >> n >> m;

        cout << "Case #" << cases << ":" << endl;

        for (int i = 0; i < n * 2 + 1; i++)
        {
            string row = "";
            string add = (i % 2 ? "|." : "+-");
            string end = (i % 2 ? "|" : "+");
            for (int j = 0; j < m; j++)
                row += add;
            row += end;
            if (i < 2)
                row[0] = row[1] = '.';
            cout << row << endl;
        }
    }

    return 0;
}