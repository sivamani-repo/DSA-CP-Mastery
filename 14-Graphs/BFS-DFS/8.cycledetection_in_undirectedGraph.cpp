```cpp
/*
===========================================================
           Cycle Detection in Undirected Graph (DFS)
===========================================================

Algorithm:
1. Start DFS from every unvisited node.
2. Mark the current node as visited.
3. Traverse all adjacent vertices:
   - If the neighbour is unvisited, continue DFS.
   - If the neighbour is already visited and is not the
     parent, a cycle exists.
4. If no such neighbour is found, the graph has no cycle.

Time Complexity : O(V + E)
Space Complexity: O(V)

Author : Sivamani
===========================================================
*/

#include <iostream>
#include <vector>
using namespace std;

// DFS function to detect cycle
bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[node] = true;

    for (int neigh : adj[node])
    {
        // Visit unvisited neighbour
        if (!vis[neigh])
        {
            if (dfs(neigh, node, adj, vis))
                return true;
        }
        // Visited neighbour other than parent -> Cycle found
        else if (neigh != parent)
        {
            return true;
        }
    }

    return false;
}

// Function to check cycle in all connected components
bool isCycle(int V, vector<vector<int>> &adj)
{
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, vis))
                return true;
        }
    }

    return false;
}

int main()
{
    /*
        Graph

            0 -------- 1
            |          |
            |          |
            3          2
            |          |
            |          |
            4          5

        No cycle exists.
    */

    int V = 6;

    vector<vector<int>> adj =
    {
        {1, 3},   // 0
        {0, 2},   // 1
        {1, 5},   // 2
        {0, 4},   // 3
        {3},      // 4
        {2}       // 5
    };

    if (isCycle(V, adj))
        cout << "Cycle Detected";
    else
        cout << "No Cycle Found";

    return 0;
}
```
