#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;
 
int microseconds(int n, string s, vector<int>& v) {
    int min_time = INT_MAX; // Initialize to a very large value
 
    // Loop through the particles to find potential collisions
    for (int i = 0; i < n - 1; i++) {
        // Check if there is a pair of particles moving towards each other
        if (s[i] == 'R' && s[i + 1] == 'L') {
            // Calculate the collision time
            int collision_time = (v[i + 1] - v[i]) / 2;
            // Update the minimum time
            min_time = min(min_time, collision_time);
        }
    }
 
    // If no collision was found, return -1
    return (min_time == INT_MAX) ? -1 : min_time;
}
 
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    cout << microseconds(n, s, v) << endl;
    return 0;
}
