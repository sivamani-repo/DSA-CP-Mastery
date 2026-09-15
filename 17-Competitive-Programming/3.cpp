#include<bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin>>n>>k;
  if( ( (n+k-1) /k) % 2 !=0 )
    cout<<"YES";
  else
    cout<<"NO";
  return 0;
}
