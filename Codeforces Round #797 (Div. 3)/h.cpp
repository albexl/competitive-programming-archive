#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct segment_tree
{

    vector<int> st;

    segment_tree(int n) : st(4 * n)
    {
    }

    void update(int node, int b, int e, int pos, int val)
    {
        if (b == e)
            st[node] += val;
        else
        {
            int m = (b + e) >> 1;
            int l = node << 1;
            int r = l | 1;

            if (pos <= m)
                update(l, b, m, pos, val);
            else
                update(r, m + 1, e, pos, val);
            st[node] = st[l] + st[r];
        }
    }

    int query(int node, int b, int e, int i, int j)
    {
        if (b >= i && e <= j)
            return st[node];
        if (b > j || e < i)
            return 0;
        int m = (b + e) >> 1;
        int l = node << 1;
        int r = l | 1;

        int L = query(l, b, m, i, j);
        int R = query(r, m + 1, e, i, j);

        return L + R;
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

        segment_tree st(n);
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            ans += (ll)st.query(1, 1, n, x, n);
            st.update(1, 1, n, x, +1);
        }

        cout << ans << endl;
    }

    return 0;
}