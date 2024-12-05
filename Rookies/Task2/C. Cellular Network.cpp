#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
bool can_cover_all_cities(const vector<int>& cities, const vector<int>& towers, int r) {
    int i = 0;  // pointer for cities
    int m = towers.size();
    
    for (int city : cities) {
        // Move the pointer to the nearest tower within distance r
        while (i < m && abs(towers[i] - city) > r) {
            i++;
        }
        // If we've explored all the towers or the tower isn't close enough, return false
        if (i == m || abs(towers[i] - city) > r) {
            return false;
        }
    }
    return true;
}
 
int binary_search_min_r(const vector<int>& cities, const vector<int>& towers) {
    int low = 0, high = 1e9, result = high;  //le9 ===>the max we can get
 
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if we can cover all cities with this r
        if (can_cover_all_cities(cities, towers, mid)) {
            result = mid;  // This r works, try smaller r
            high = mid - 1;
        } else {
            low = mid + 1;  // Increase r to cover all cities
        }
    }
    return result;  //  the minimal r
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<int> cities(n), towers(m);
 
    for (int i = 0; i < n; ++i) {
        cin >> cities[i];
    }
 
    for (int i = 0; i < m; ++i) {
        cin >> towers[i];
    }
 
    // Special case handling: When only one city and one tower are present
    if (n == 1 && m == 1) {
        cout << abs(cities[0] - towers[0]) << endl;
    } else {
        int result = binary_search_min_r(cities, towers);
        cout << result << endl;
    }
 
    return 0;
}
