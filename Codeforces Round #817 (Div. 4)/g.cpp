#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef long long ll;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    std::random_device seed_gen;
    std::mt19937_64 engine(seed_gen());

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        set<int> S;
        while (true)
        {
            S.clear();
            int xr = 0;
            while (S.size() < n - 1)
            {
                int x = engine() % (1ll << 31);
                if (S.find(x) == S.end())
                {
                    S.insert(x);
                    xr ^= x;
                }
            }
            if (S.find(xr) == S.end())
            {
                S.insert(xr);
                break;
            }
        }

        for (auto &el : S)
            cout << el << " ";
        cout << "\n";
    }

    return 0;
}