#include <iostream>
#include <vector>
using namespace std;
 
int untreatedCrimes(int n ,vector<int>& v) {
	int officers = 0;
	int untreated = 0;
 
	for (int i = 0; i < n; i++) {
		if (v[i] > 0) {
			officers+= v[i];
		}
 
		else if (v[i] < 0 && officers >0) {
			officers--;
		}
 
		else if (v[i] < 0 && officers <= 0) {
			untreated++;
		}
	}
 
	return untreated;
 
}
 
int main() {
  
	int n; cin >> n;
	vector<int>v(n);
 
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
 
	cout << untreatedCrimes(n, v);
}
