#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> validMoves = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

bool is_within_bounds(pair<int, int> position) {
    return position.first >= 0 && position.first < 8 &&
        position.second >= 0 && position.second < 8;
}

int bfs(pair<int, int> source, pair<int, int> destination) {

    // Initialize a 2D visited array (8x8)
    vector<vector<bool>> visited(8, vector<bool>(8, false));

    queue<pair<pair<int, int>, int>> q; // Pair of position and distance
    q.push({ source, 0 }); 
    visited[source.first][source.second] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        pair<int, int> position = current.first;
        int distance = current.second;

        if (position == destination) {
            return distance; 
        }

        // Explore all valid knight moves from the current position
        for (pair<int,int> move : validMoves) {
            pair<int, int> neighbor = { position.first + move.first, position.second + move.second };

            if (is_within_bounds(neighbor) && !visited[neighbor.first][neighbor.second]) {
                visited[neighbor.first][neighbor.second] = true;
                q.push({ neighbor, distance + 1 }); 
            }
        }
    }

    return -1; // will never happen anyway... I hope
}

int main() {

    // here I wanted to convert the input (string) to a pair of values . ex : a1 is just (0,0),so I used an enum
    enum mapping_values {
        a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7
    };

    int t;
    cin >> t;
    while (t--) {
        string source, destination;
        cin >> source >> destination;

        pair<int, int> source_pos = { mapping_values(source[0] - 'a'), source[1] - '1' };
        pair<int, int> destination_pos = { mapping_values(destination[0] - 'a'), destination[1] - '1' };


        cout << bfs(source_pos, destination_pos) << endl;
    }

    return 0;
}
