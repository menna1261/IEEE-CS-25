#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int shops(vector<int>& prices, int coins) {
    int low = 0;
    int high = prices.size() - 1;
    int result = -1;  // starting from -1 (the last affordable index aka shop)
 
    while (low <= high) {
        int middle = low + (high - low) / 2;
 
        if (prices[middle] <= coins) {
            result = middle;  // Update result with the last affordable index
            low = middle + 1; // Search in the right half
        }
        else {
            high = middle - 1; // Search in the left half
        }
    }
 
    return result + 1; // Convert 0-based index to count (add 1)
}
 
int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
 
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());  // Sort for binary search
 
    int q;
    cin >> q;
 
    while (q--) {
        int coins;
        cin >> coins;
        cout << shops(prices, coins) << endl;
    }
 
    return 0;
}
