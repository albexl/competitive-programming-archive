#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct segment_tree
{

    vector<int> st;

    segment_tree(int n) : st(4 * n)
    {
    }

    void update(int node, int b, int e, int x)
    {
        if (b == e)
            st[node]++;
        else
        {
            int m = (b + e) >> 1;
            int l = node << 1;
            int r = l | 1;

            if (x <= m)
                update(l, b, m, x);
            else
                update(r, m + 1, e, x);
            st[node] = st[l] + st[r];
        }
    }

    int query(int node, int b, int e, int i, int j)
    {
        if (b >= i && e <= j)
            return st[node];
        if (e < i || b > j)
            return 0;
        int m = (b + e) >> 1;
        int l = node << 1;
        int r = l | 1;
        return query(l, b, m, i, j) + query(r, m + 1, e, i, j);
    }
};

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<ll> b = a;
        for (int i = 0; i <= n; i++)
            b.push_back(i);
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        int N = b.size() + 5;
        segment_tree st(N);

        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] < i + 1)
            {
                int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
                ans += 1ll * st.query(1, 1, N, 1, idx - 1);
                idx = lower_bound(b.begin(), b.end(), i + 1) - b.begin() + 1;
                st.update(1, 1, N, idx);
            }
        }

        cout << ans << endl;
    }

    return 0;
}