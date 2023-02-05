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

    while (t--)
    {
        int n;
        string s;

        cin >> n >> s;

        int ans = 0;

        map<char, int> mp1, mp2;
        int cnt1 = 0, cnt2 = 0;

        cnt1 = 1;
        mp1[s[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            mp2[s[i]]++;
            if (mp2[s[i]] == 1)
                cnt2++;
        }

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, cnt1 + cnt2);
            if (i + 1 != n)
            {
                mp1[s[i + 1]]++;
                if (mp1[s[i + 1]] == 1)
                    cnt1++;
                mp2[s[i + 1]]--;
                if (mp2[s[i + 1]] == 0)
                    cnt2--;
            }
        }

        cout << ans << endl;
    }

    return 0;
}