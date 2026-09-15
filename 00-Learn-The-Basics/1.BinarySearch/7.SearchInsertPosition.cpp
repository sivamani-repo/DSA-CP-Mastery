#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<char> a(n);
    for (auto &i : a)
        cin >> i;
    set<char> s;
    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        char c = a[i];
        if (c >= 'A' && c <= 'Z')
        {
            s.insert(a.begin() + j, a.begin() + i);
            ans = max(ans, (int)s.size());
            s.clear();
            j = i + 1;
        }
    }
    if (j < n)
    {
        s.insert(a.begin() + j, a.end());
        ans = max(ans, (int)s.size());
    }
    cout << ans << '\n';
    return 0;
}