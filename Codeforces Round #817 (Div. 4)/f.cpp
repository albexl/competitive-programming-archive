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
        int n, m;
        cin >> n >> m;

        vector<string> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        bool ok = true;

        vector<int> dx = {1, -1, 0, 0, 1, 1, -1, -1};
        vector<int> dy = {0, 0, 1, -1, 1, -1, 1, -1};

        vector<vector<bool>> flag(n, vector<bool>(m));

        for (int i = 0; i < n && ok; i++)
            for (int j = 0; j < m && ok; j++)
            {
                if (a[i][j] == '*' && !flag[i][j])
                {
                    set<pii> l_shape;
                    queue<pii> Q;
                    Q.push({i, j});
                    l_shape.insert({i, j});
                    flag[i][j] = true;
                    while (!Q.empty())
                    {
                        int x = Q.front().first;
                        int y = Q.front().second;
                        Q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !flag[nx][ny] && a[nx][ny] == '*')
                            {
                                flag[nx][ny] = true;
                                Q.push({nx, ny});
                                l_shape.insert({nx, ny});
                            }
                        }
                    }

                    if (l_shape.size() != 3)
                    {
                        ok = false;
                        continue;
                    }

                    set<int> X, Y;
                    for (auto &el : l_shape)
                    {
                        X.insert(el.first);
                        Y.insert(el.second);
                    }

                    if (X.size() == 1 || Y.size() == 1)
                    {
                        ok = false;
                        continue;
                    }

                    for (auto &el : l_shape)
                    {
                        int x = el.first;
                        int y = el.second;
                        for (int k = 0; k < 8; k++)
                        {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '*' && l_shape.find(pii(nx, ny)) == l_shape.end())
                                ok = false;
                        }
                    }
                }
            }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}