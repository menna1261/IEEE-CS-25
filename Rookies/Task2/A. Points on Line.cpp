#include <iostream>
#include <vector>
using namespace std;
 
int binarySearch(vector<int>& points, int left, int d) {
    long long low = left, high = points.size() - 1, result = left;
 
    while (low <= high) {
        long long mid = low + (high - low) / 2;
 
        // Check if the distance from the current point to the leftmost point is within d
        if (points[mid] - points[left] <= d) {
            result = mid;  
            low = mid + 1; 
        }
        else {
            high = mid - 1; 
        }
    }
 
    return result;  // Return the rightmost valid point
}
 
int main() {
    long long n, d;
    cin >> n >> d;
 
    vector<int> points(n);
    for (long long i = 0; i < n; i++) {
        cin >> points[i];
    }
 
    long long result = 0;  
 
    for (long long i = 0; i < n - 2; i++) {
        long long j = binarySearch(points, i, d);
 
        long long count = j - i;
        if (count >= 2) {  // At least 3 points are needed to form a triplet
            result += (long long)(count * (count - 1)) / 2;  // Choose 2 points out of 'count', using the combination formula
        }
    }
 
    cout << result << endl;
    return 0;
}
