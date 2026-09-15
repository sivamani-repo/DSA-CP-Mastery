#include <bits/stdc++.h>
using namespace std;
string solve(vector<int> a, int n)
{
  int p = 0;
  for (int i = 1; i < n; ++i)
  {
    if (a[i] > a[i - 1])
      if (p!= 0)
        return "NO";
    else if (a[i] == a[i - 1])
    {
      if (p == 2)
        return "NO";
      p = 1;
    }
    else
      p = 2;
  }
  return "YES";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  cout << solve(a, n);
  return 0;
}