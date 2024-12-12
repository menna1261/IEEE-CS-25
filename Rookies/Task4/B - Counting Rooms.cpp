#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

void bfs(vector<vector<char>>& mapp, vector<vector<bool>>& visited, int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i, j });
    visited[i][j] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int new_x = x + directions[k].first;
            int new_y = y + directions[k].second;

            if (new_x >= 0 && new_x < mapp.size() && new_y >= 0 && new_y < mapp[0].size() &&
                !visited[new_x][new_y] && mapp[new_x][new_y] == '.') {
                visited[new_x][new_y] = true;
                q.push({ new_x, new_y });
            }
        }
    }
}

void find_rooms(int n, int m, vector<vector<char>>& mapp) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int room_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mapp[i][j] == '.' && !visited[i][j]) {
                bfs(mapp, visited, i, j);  
                room_count++;  
            }
        }
    }
    cout << room_count << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> mapp(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapp[i][j];
        }
    }

    find_rooms(n, m, mapp);

    return 0;
}
