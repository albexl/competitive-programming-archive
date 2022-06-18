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

        vector<string> a(8);
        for (int i = 0; i < 8; i++)
            cin >> a[i];
        int r = 0, c = 0;
        for (int i = 1; i < 7; i++)
        {
            for (int j = 1; j < 7; j++)
            {
                if (a[i][j] == '#' && a[i - 1][j - 1] == '#' && a[i - 1][j + 1] == '#' && a[i + 1][j - 1] == '#' && a[i + 1][j + 1] == '#')
                    r = i, c = j;
            }
        }
        cout << r + 1 << " " << c + 1 << endl;
    }

    return 0;
}