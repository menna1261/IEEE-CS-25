#include <iostream>
#include <vector>
using namespace std;
 
int numberOfSeconds(int n, vector<int>& v) {
    int max_index = 0; // First occurrence of max height
    int min_index = 0; // Last occurrence of min height
 
    // Find indices for max and min
    for (int i = 0; i < n; i++) {
        if (v[i] > v[max_index]) {
            max_index = i;
        }
        if (v[i] <= v[min_index]) { // Use <= to get the rightmost min
            min_index = i;
        }
    }
 
    // Calculate moves
    int moves = max_index + (n - 1 - min_index); // Moves to front + moves to end
 
    // If max_index is before min_index, subtract 1 as their moves overlap
    if (max_index > min_index) {
        moves -= 1;
    }
 
    return moves;
}
 
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    cout << numberOfSeconds(n, v) << endl;
}
