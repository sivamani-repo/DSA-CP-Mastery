// LeetCode 877 - Stone Game
// Intuition:
// At every step, the current player has only 2 choices:
// 1. Take the left pile.
// 2. Take the right pile.
// stone(i, j) means the maximum score difference
// the current player can achieve from index i to j.
// After taking a pile, the opponent becomes the current player,
// so we subtract the opponent's best score difference.

// Recursion 
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stone(vector<int>& arr, int i, int j)
    {
        // Base case: only one pile is left
        if (i == j)
            return arr[i];

        // Take the left pile
        int left = arr[i] - stone(arr, i + 1, j);

        // Take the right pile
        int right = arr[j] - stone(arr, i, j - 1);

        // Choose the move with maximum advantage
        return max(left, right);
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {5, 3, 4, 5};

    int n = arr.size();

    int result = obj.stone(arr, 0, n - 1);

    if (result > 0)
        cout << "Alice Wins";
    else
        cout << "Bob Wins";

    return 0;
}

/*
Time Complexity: O(2^n)
Space Complexity: O(n) - recursion stack
*/
