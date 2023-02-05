#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int digit_sum(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

struct segment_tree
{

    vector<int> st, sum;

    segment_tree(int n, vector<int> &a) : st(4 * n), sum(4 * n)
    {
        build(1, 1, n, a);
    }

    void build(int node, int b, int e, vector<int> &a)
    {
        if (b == e)
        {
            st[node] = a[b];
            if (st[node] / 10 == 0)
                sum[node] = 1;
        }
        else
        {
            int m = (b + e) >> 1;
            int l = node << 1;
            int r = l | 1;

            build(l, b, m, a);
            build(r, m + 1, e, a);

            sum[node] = sum[l] + sum[r];
        }
    }

    void update(int node, int b, int e, int l, int r)
    {
        if (sum[node] == e - b + 1)
            return;

        if (e < l || b > r)
            return;

        if (b == e)
        {
            st[node] = digit_sum(st[node]);
            if (st[node] / 10 == 0)
                sum[node] = 1;
            return;
        }

        int m = (b + e) >> 1;
        int left = node << 1;
        int right = left | 1;

        update(left, b, m, l, r);
        update(right, m + 1, e, l, r);

        sum[node] = sum[left] + sum[right];
    }

    int query(int node, int b, int e, int pos)
    {
        if (b == e)
            return st[node];
        else
        {
            int m = (b + e) >> 1;
            int left = node << 1;
            int right = left | 1;

            if (pos <= m)
                return query(left, b, m, pos);
            return query(right, m + 1, e, pos);
        }
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
        int n, q;
        cin >> n >> q;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        segment_tree st(n, a);

        while (q--)
        {
            int op;
            cin >> op;

            if (op == 1)
            {
                int l, r;
                cin >> l >> r;
                st.update(1, 1, n, l, r);
            }
            else
            {
                int x;
                cin >> x;
                cout << st.query(1, 1, n, x) << endl;
            }
        }
    }

    return 0;
}