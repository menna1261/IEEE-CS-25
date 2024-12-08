#include <iostream>
#include <vector>
using namespace std;
 
void solve(vector<int>& chocolates, int alice_Count, int bob_Count) {
    int n = chocolates.size();
    int left = 0, right = n - 1; 
    int time_Alice = 0, time_Bob = 0;
 
    alice_Count = 0;
    bob_Count = 0;
 
    while (left <= right) {
        if (time_Alice <= time_Bob) {
            // Alice eating the chocolate
            time_Alice += chocolates[left];
            ++alice_Count;
            ++left;
        } else {
            // Bob 
            time_Bob += chocolates[right];
            ++bob_Count;
            --right;
        }
    }
}
 
int main() {
    int n;
    cin >> n;
 
    vector<int> chocolates(n);
    for (int i = 0; i < n; ++i) {
        cin >> chocolates[i];
    }
 
    int alice_Count = 0, bob_Count = 0;
 
    solve(chocolates, aliceCount, bobCount);
 
    cout << aliceCount << " " << bobCount << endl;
 
    return 0;
}
