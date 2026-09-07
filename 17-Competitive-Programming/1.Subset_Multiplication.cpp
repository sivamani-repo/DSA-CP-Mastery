#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    ll ans = 1;

    for (int i = 0; i < n - 1; i++)
      ans = lcm(ans, a[i] / gcd(a[i], a[i + 1]));

    cout << ans << '\n';
  }
}

