#include <iostream>
#include <unordered_map>
using namespace std;
 
string OriginalMessage(char direction, string message) {
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    unordered_map<char, int> keyIndex;
 
    // Precompute the index of each character in the keyboard
    for (int i = 0; i < keyboard.size(); i++) {
        keyIndex[keyboard[i]] = i;
    }
 
    string originalMessage = "";
    int shift = (direction == 'R') ? -1 : 1;
 
    // Construct the original message
    for (char ch : message) {
        originalMessage += keyboard[keyIndex[ch] + shift];
    }
 
    return originalMessage;
}
 
int main() {
    char direction;
    string message;
 
    cin >> direction >> message;
 
    cout << OriginalMessage(direction, message) << endl;
 
    return 0;
}
