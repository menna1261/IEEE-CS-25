#include <iostream>
#include <vector>
using namespace std;
 // here I used the sliding window approach to slove the problem
int max_books(int n, int t, const vector<int>& times) {
    int left = 0;  
    int right = 0; 
    int current_sum = 0;  
    int max_books = 0; 
    
    while (right < n) {
        current_sum += times[right];  // Add the current book time to the window
        
        // If current_sum exceeds t, slide the window from the left
        while (current_sum > t) {
            current_sum -= times[left];
            left++;
        }
        
        // Update the max num of books 
        max_books = max(max_books, right - left + 1);
        
        right++;
    }
    
    return max_books;
}
 
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> times(n);
    
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }
    
    cout << max_books(n, t, times) << endl;
}
