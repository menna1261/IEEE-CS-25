#include <iostream>
using namespace std;

void seq(long long n) {
    cout << n << " "; 

    
    if (n == 1) {
        return;
    }

    if (n % 2 == 0) {
        seq(n / 2); 
    }
    else {
        seq(3 * n + 1); 
    }
}

int main() {
    long long n;
    cin >> n;

    seq(n); 
    return 0;
}
