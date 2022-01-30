#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 41;
const int oo = 1e9;

int dp[maxn][maxn][maxn][maxn];
int n, A, B;
string x;

int solve(int pos, int remA, int remB, int dif)
{
    if (pos == n)
    {
        if (dif == n || dif == 0)
            return oo;
        if (remA != 0 || remB != 0)
            return oo;
        return abs(dif - (n - dif));
    }

    if (dp[pos][remA][remB][dif] != -1)
        return dp[pos][remA][remB][dif];

    int s1 = solve(pos + 1, (remA * 10 + x[pos] - '0') % A, remB, dif + 1);
    int s2 = solve(pos + 1, remA, (remB * 10 + x[pos] - '0') % B, dif);

    return dp[pos][remA][remB][dif] = min(s1, s2);
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> A >> B;
        cin >> x;
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, 0, 0);

        if (ans == oo)
            cout << -1 << "\n";
        else
        {
            int pos = 0, remA = 0, remB = 0, dif = 0;
            string rec = "";
            while (pos < n)
            {
                int s1 = solve(pos + 1, (remA * 10 + x[pos] - '0') % A, remB, dif + 1);
                int s2 = solve(pos + 1, remA, (remB * 10 + x[pos] - '0') % B, dif);
                if (s1 < s2)
                {
                    rec += "R";
                    dif++;
                    remA = (remA * 10 + x[pos] - '0') % A;
                }
                else
                {
                    rec += "B";
                    remB = (remB * 10 + x[pos] - '0') % B;
                }
                pos++;
            }

            cout << rec << "\n";
        }
    }

    return 0;
}