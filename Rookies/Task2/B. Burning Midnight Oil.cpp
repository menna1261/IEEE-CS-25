#include <iostream>
#include <cmath>
using namespace std;

long long compute_v(long long v, int k) {
    long long total = 0;
    long long power = 1; // k^0 initially
    while (v / power > 0) {
        total += v / power;
        if (power > LLONG_MAX / k) 
          break; // Avoid overflow
        power *= k; 
    }
    return total;
}

int main() {
    long long n;
    int k;
    cin >> n >> k;

    long long low = 1, high = n, res = n;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (compute_v(mid, k) >= n) {
            res = mid; 
            high = mid - 1;
        }
        else {
            low = mid + 1; // Need a larger v
        }
    }

    cout << res << endl;
    return 0;
}
