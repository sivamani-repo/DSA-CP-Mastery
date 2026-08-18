// LeetCode 1140 - Stone Game II

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int m, vector<int>& suff, vector<vector<int>>& dp, int n)
{
    if (i >= n)
        return 0;

    if (i + 2 * m >= n)
        return suff[i];

    if (dp[i][m] != -1)
        return dp[i][m];

    int ans = 0;

    for (int x = 1; x <= 2 * m; x++)
    {
        int opponent = solve(i + x, max(m, x), suff, dp, n);

        int current = suff[i] - opponent;

        ans = max(ans, current);
    }

    return dp[i][m] = ans;
}

int stoneGameII(vector<int>& piles)
{
    int n = piles.size();

    vector<int> suff(n);
    suff[n - 1] = piles[n - 1];

    for (int i = n - 2; i >= 0; i--)
        suff[i] = piles[i] + suff[i + 1];

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return solve(0, 1, suff, dp, n);
}

int main()
{
    vector<int> piles = {2, 7, 9, 4, 4};

    cout << "Input: ";
    for (int x : piles)
        cout << x << " ";

    cout << "\nOutput: " << stoneGameII(piles);

    return 0;
}

/*
Input:
2 7 9 4 4

Output:
10

Time Complexity: O(N^3)
Space Complexity: O(N^2)
*/
