#include <bits/stdc++.h>
using namespace std;
//!   a[i]>=x
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<int> a(n);

  for (int &i : a)
    cin >> i;

  int l = 0, r = n;

  while (l < r)
  {
    int mid = l + (r - l) / 2;

    if (a[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }

  cout << l << '\n';

  return 0;
}
//! auto it1 = lower_bound(a.begin(), a.end(), x);