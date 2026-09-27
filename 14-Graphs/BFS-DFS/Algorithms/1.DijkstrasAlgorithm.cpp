#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

vector<ll> dijkstra(int n, const vector<vector<P>>& adj, int src)
 {
    // dist[v] = shortest distance from src to v
    vector<ll> dist(n + 1, LLONG_MAX);

    // min-heap: {distance, vertex}
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Ignore stale heap entries
        if (d != dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            // Relaxation
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<P>> adj(n + 1);

    // Input: directed weighted graph
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});

        // For an undirected graph:
        // adj[v].push_back({u, w});
    }

    int src;
    cin >> src;

    vector<ll> dist = dijkstra(n, adj, src);

    for (int v = 1; v <= n; ++v) {
        if (dist[v] == LLONG_MAX)
            cout << -1 << ' ';
        else
            cout << dist[v] << ' ';
    }

    cout << '\n';
}