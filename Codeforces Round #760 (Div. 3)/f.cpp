#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int oo = 2e9;

struct union_find
{

    vector<int> sz, pi, mn;

    union_find(int n, vector<int> times) : sz(n), pi(n), mn(n)
    {
        for (int i = 0; i < n; i++)
        {
            sz[pi[i] = i] = 1;
            mn[i] = times[i];
        }
    }

    int root(int x)
    {
        if (pi[x] == x)
            return x;
        return root(pi[x]);
    }

    bool merge(int a, int b)
    {
        a = root(a);
        b = root(b);

        if (a == b)
            return false;

        if (sz[a] > sz[b])
            swap(a, b);

        pi[a] = b;
        sz[b] += sz[a];
        mn[b] = min(mn[b], mn[a]);

        return true;
    }
};

int search_right(int val, int x, vector<int> &v)
{
    int pos = lower_bound(v.begin(), v.end(), val) - v.begin();
    int ans = -1;
    if (pos + 1 < (int)v.size() && v[pos + 1] <= x)
        ans = v[pos + 1];

    return ans;
}

int search_left(int val, int x, vector<int> &v)
{
    int pos = lower_bound(v.begin(), v.end(), val) - v.begin();
    int ans = -1;
    if (pos > 0 && v[pos - 1] >= x)
        ans = v[pos - 1];

    return ans;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<pii, int> mp;
        map<int, vector<int>> mpX, mpY;

        vector<int> x(n), y(n), times(n);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i] >> times[i];
            mp[pii(x[i], y[i])] = i;
            mpX[x[i]].push_back(y[i]);
            mpY[y[i]].push_back(x[i]);
        }

        for (auto &el : mpX)
            sort(el.second.begin(), el.second.end());

        for (auto &el : mpY)
            sort(el.second.begin(), el.second.end());

        union_find ds(n, times);

        for (int i = 0; i < n; i++)
        {
            int Y = search_right(y[i], y[i] + k, mpX[x[i]]);
            if (Y != -1)
            {
                int pos = mp[pii(x[i], Y)];
                ds.merge(i, pos);
            }

            Y = search_left(y[i], y[i] - k, mpX[x[i]]);
            if (Y != -1)
            {
                int pos = mp[pii(x[i], Y)];
                ds.merge(i, pos);
            }

            int X = search_right(x[i], x[i] + k, mpY[y[i]]);
            if (X != -1)
            {
                int pos = mp[pii(X, y[i])];
                ds.merge(i, pos);
            }

            X = search_left(x[i], x[i] - k, mpY[y[i]]);
            if (X != -1)
            {
                int pos = mp[pii(X, y[i])];
                ds.merge(i, pos);
            }
        }

        set<int> R;
        for (int i = 0; i < n; i++)
            R.insert(ds.root(i));

        vector<int> cluster_times;
        for (auto &x : R)
            cluster_times.push_back(ds.mn[x]);

        sort(cluster_times.begin(), cluster_times.end());

        int ans = oo;
        for (int i = 0; i < cluster_times.size(); i++)
        {
            int r = (int)cluster_times.size() - 1 - i;
            int left = r ? cluster_times[r - 1] : 0;
            ans = min(ans, max(i, left));
        }

        cout << ans << endl;
    }

    return 0;
}