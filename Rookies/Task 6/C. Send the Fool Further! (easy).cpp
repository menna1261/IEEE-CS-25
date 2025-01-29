#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000;

int n, u, v, c, maxSum = 0;
bool vis[N];
vector<pair<int, int>> adj[N];

void dfs(int node, int currentSum) {
    vis[node] = true;

    for (int i = 0; i < adj[node].size(); i++) {
        int nextNode = adj[node][i].first;
        int cost = adj[node][i].second;

        if (!vis[nextNode]) {
            dfs(nextNode, currentSum + cost);
        }
    }

    maxSum = max(maxSum, currentSum);
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> c;
        adj[u].push_back({ v, c });
        adj[v].push_back({ u, c });
    }

    dfs(0, 0);

    cout << maxSum << endl;
    return 0;
}
