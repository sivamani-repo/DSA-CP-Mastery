#include<bits/stdc++.h>
using namespace std;

//always sorted order
void print(set<string>&s)
{
  for(string value:s)
    cout<<value<<endl;
      
  for(auto it=s.begin() ;it!=s.end() ;++it)
    cout<<(*it)<<endl;
    
}

int main()
{
  //all operations log(n)
  set<string>s;
  s.insert("abc");
  s.insert("zsdf");
  s.insert("bcd");
  s.insert("abc"); //duplicate not allowed
  auto it= s.find("abc");
  if(it !=s.end())
    s.erase(it);
  print(s);
}