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
        int n, k;
        string s;

        cin >> n >> k >> s;

        if (k >= 25)
        {
            for (int i = 0; i < n; i++)
                cout << "a";
            cout << endl;
            continue;
        }

        // cout << "here" << endl;

        vector<char> convert(26);
        for (int i = 0; i < 26; i++)
            convert[i] = (char)(i + 'a');

        int pos = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] - 'a' > k)
            {
                pos = i;
                break;
            }
        }

        // cout << pos << " " << n << " pos n" << endl;

        if (pos == -1)
        {
            for (int i = 0; i < n; i++)
                cout << "a";
            cout << endl;
            continue;
        }

        // cout << pos << " pos" << endl;

        int mx = -1;
        for (int i = 0; i < pos; i++)
            mx = max(mx, s[i] - 'a');

        // cout << pos << " " << mx << endl;

        for (int i = 0; i <= mx; i++)
            convert[i] = 'a';

        if (mx != -1)
            k -= mx;

        for (int i = pos; i <= pos && k; i++)
        {
            char cur = convert[s[i] - 'a'];
            int pos = cur - 'a';
            int mn = min(k, pos);
            int lo = pos - mn;
            k -= mn;
            for (int j = lo; j <= pos; j++)
                convert[j] = (char)(lo + 'a');
        }

        for (int i = 0; i < n; i++)
            cout << convert[s[i] - 'a'];
        cout << endl;
    }

    return 0;
}