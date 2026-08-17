// LeetCode 877 - Stone Game

// Intuition:
// dp[i][j] = maximum score difference the current player
// can achieve from piles i to j.
// We start with small subarrays and build the answer
// for bigger subarrays.
// Base case:
// When i == j, only one pile is available,
// so dp[i][i] = arr[i].
 //Tabulation
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stone(vector<int>& arr)
    {
        int n = arr.size();

        // 2D DP because our state has i and j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: one pile
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = arr[i];
        }

        // Build answers for increasing subarray length
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;

                // Take left pile
                int left = arr[i] - dp[i + 1][j];

                // Take right pile
                int right = arr[j] - dp[i][j - 1];

                // Choose maximum advantage
                dp[i][j] = max(left, right);
            }
        }

        return dp[0][n - 1];
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {5, 3, 4, 5};

    int result = obj.stone(arr);

    if (result > 0)
        cout << "Alice Wins";
    else
        cout << "Bob Wins";

    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/
