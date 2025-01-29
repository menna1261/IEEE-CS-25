#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;

int n, p[N];
bool vis[N];
vector<int> adj[N];

void dfs(int node) {
    vis[node] = true;
    for (int i = 0; i < adj[node].size();i++) {
        int next = adj[node][i];
        if (!vis[next])
            dfs(next);
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);  
    }

    int trees = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            trees++;
            dfs(i);
        }
    }

    cout << trees << endl;
    return 0;
}
