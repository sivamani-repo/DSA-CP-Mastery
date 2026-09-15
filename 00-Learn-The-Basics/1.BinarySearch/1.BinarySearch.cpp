#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);

    for (int &i : a)
        cin >> i;

    sort(a.begin(), a.end());

    int l = 0, r = n - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] == x)
        {
            cout << mid << '\n';
            return 0;
        }

        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << -1 << '\n';

    return 0;
}

