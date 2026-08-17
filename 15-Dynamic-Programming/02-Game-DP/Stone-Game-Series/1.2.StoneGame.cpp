// LeetCode 877 - Stone Game
// Intuition:
// At every step, the current player has 2 choices:
// 1. Take the left pile.
// 2. Take the right pile.
// stone(i, j) = maximum score difference the current player
// can achieve from index i to j.
// We use dp[i][j] to store the answer for each state.
// If the same state appears again, we directly return its value.
//Memoization
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stone(vector<int>& arr, int i, int j, vector<vector<int>>& dp)
    {
        // Base case: only one pile is left
        if (i == j)
            return arr[i];

        // If already calculated, return stored answer
        if (dp[i][j] != -1)
            return dp[i][j];

        // Take the left pile
        int left = arr[i] - stone(arr, i + 1, j, dp);

        // Take the right pile
        int right = arr[j] - stone(arr, i, j - 1, dp);

        // Store and return the best answer
        return dp[i][j] = max(left, right);
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {5, 3, 4, 5};

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    int result = obj.stone(arr, 0, n - 1, dp);

    if (result > 0)
        cout << "Alice Wins";
    else
        cout << "Bob Wins";

    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n^2) + O(n) recursion stack
*/
