#include <iostream>
using namespace std;
#define ll long long int


ll n;
ll* arr;

ll divide_apples(int i , ll G1_w , ll G2_w) {
    if (i == n) 
        return abs(G1_w - G2_w);

    ll addToG1 = divide_apples(i + 1, G1_w + arr[i], G2_w);
    ll addToG2 = divide_apples(i + 1, G1_w, G2_w + arr[i]);

    return min(addToG1, addToG2);
    
}


int main()
{

    cin >> n;
    arr = new ll[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << divide_apples(0, 0, 0);
    delete[] arr;
}
