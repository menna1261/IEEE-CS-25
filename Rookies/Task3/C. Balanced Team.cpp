#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Balance(vector<int>& skills) {
    int n = skills.size();
    int left = 0, max_Size = 0;

    for (int right = 0; right < n; ++right) {
        while (skills[right] - skills[left] > 5) {
            ++left;
        }
        max_Size = max(max_Size, right - left + 1);
    }

    return max_Size;
}

int main() {
    int n;
    cin >> n;
    vector<int> skills(n);
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
    }

    sort(skills.begin(), skills.end());

    cout << Balance(skills) << endl;

    return 0;
}
