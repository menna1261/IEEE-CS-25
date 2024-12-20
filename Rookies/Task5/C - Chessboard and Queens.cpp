#include <iostream>
#include <vector>
#include <string>
using namespace std;

int _count = 0;
vector<string> board(8);       
vector<bool> columns(8, false); 
vector<bool> diag1(15, false);  
vector<bool> diag2(15, false);  

void chesss(int row) {
    if (row == 8) {
        _count++;
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (board[row][col] == '.' && !columns[col] && !diag1[row + col] && !diag2[row - col + 7]) {

            columns[col] = diag1[row + col] = diag2[row - col + 7] = true;
            chesss(row + 1);
            columns[col] = diag1[row + col] = diag2[row - col + 7] = false;
        }
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    chesss(0);

    cout << _count << endl;

    return 0;
}
