#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;  

long long fibonacci(int n) {
    if (v[n] != -1) {
        return v[n];
    }

    v[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return v[n];
}

int main() {
    int n;
    cin >> n;

    v.resize(n + 1, -1);
    
    v[0] = 0;
    v[1] = 1;

    cout << fibonacci(n) << endl;

    return 0;
}
