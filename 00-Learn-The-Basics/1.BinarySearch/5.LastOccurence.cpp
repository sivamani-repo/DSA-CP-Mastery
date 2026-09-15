#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);

    for (int &i : a)
        cin >> i;

    int l = 0, r = n - 1;
    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] == x)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (a[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}