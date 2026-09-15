#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(ll x)
{
    // return true if x is feasible
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l = 0, r = 1e18;

    while (l < r)
    {
        ll mid = l + (r - l) / 2;

        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << '\n';

    return 0;
}