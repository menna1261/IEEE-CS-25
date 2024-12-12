#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<string> graph;
vector<vector<char>> steps;
vector<vector<bool>> visited;
int n, m;

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && graph[x][y] != '#' && !visited[x][y];
}

void construct_path(int x, int y, stack<char>& path) {
    while (steps[x][y] != 'X') {
        char direction = steps[x][y];
        path.push(direction);
        if (direction == 'U') x++;
        else if (direction == 'D') x--;
        else if (direction == 'L') y++;
        else if (direction == 'R') y--;
    }
}

bool bfs(int sx, int sy, stack<char>& path) {
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    steps[sx][sy] = 'X';
    visited[sx][sy] = true;

    vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    vector<char> dir_chars = { 'U', 'D', 'L', 'R' };

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        if (graph[x][y] == 'B') {
            construct_path(x, y, path);
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;

            if (is_valid(nx, ny)) {
                visited[nx][ny] = true;
                steps[nx][ny] = dir_chars[i];
                q.push(make_pair(nx, ny));
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    graph.resize(n);
    steps.assign(n, vector<char>(m, 0));
    visited.assign(n, vector<bool>(m, false));

    pair<int, int> start, dest;

    for (int i = 0; i < n; i++) {
        cin >> graph[i]; 
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'A') {
                start = { i, j };
            }
            else if (graph[i][j] == 'B') {
                dest = { i, j };
            }
        }
    }

    stack<char> ans;
    if (bfs(start.first, start.second, ans)) {
        cout << "YES" << endl << ans.size() << endl;
        while (!ans.empty()) {
            cout << ans.top();
            ans.pop();
        }
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
