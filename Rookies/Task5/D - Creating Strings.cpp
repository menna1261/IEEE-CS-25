#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void generate(string& s, vector<string>& result, string& current, vector<bool>& used) {
    if (current.length() == s.length()) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < s.length(); i++) {
        // if used just skip
        if (used[i] || (i > 0 && s[i] == s[i - 1] && !used[i - 1])) {
            continue;
        }

        used[i] = true;
        current.push_back(s[i]);

        generate(s, result, current, used);

        used[i] = false;
        current.pop_back();
    }
}

int main() {
    string input;
    cin >> input;

    sort(input.begin(), input.end()); // 'cause we need lexicographical order

    vector<string> result; 
    string current; 
    vector<bool> used(input.length(), false); 

    generate(input, result, current, used);

    cout << result.size() << endl;

    for (int i = 0; i<result.size();i++) {

        cout << result[i] << endl;
    }

    return 0;
}
