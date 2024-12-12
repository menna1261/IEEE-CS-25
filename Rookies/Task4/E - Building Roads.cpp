#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100001;

vector<int> graph[MAXN];
bool visited[MAXN];

void bfs(int start, vector<int>& c) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        c.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> connected;

    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> c;
            bfs(i, c);
            connected.push_back(i);
        }
    }

    int k = connected.size() - 1;
    cout << k << endl;

    for (int i = 0; i < k; i++) {
        cout << connected[i] << " " << connected[i + 1] << endl;
    }

    return 0;
}
