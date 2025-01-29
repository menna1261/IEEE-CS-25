#include <iostream>
#include<vector>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

const int N = 1000;
int n, m, ans; int S[N][N]; bool vis[N][N];


bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]&& S[x][y]> 0;
}


void dfs(int x, int y) {
    vis[x][y] = 1;
    ans += S[x][y];
    
    for (int i = 0; i < 4; i++) {

        int Nx = x + dx[i];
        int Ny = y + dy[i];

        if (valid(Nx, Ny)) {
            
            dfs(Nx, Ny);
        }
    }

}

int main()
{
    int t; cin >> t;
    while (t--) {

        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = false;
            }
        }
        
  
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                cin >> S[i][j];

        int maxRes = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j] && valid(i,j)) {
                    ans = 0;
                    dfs(i, j);
                    
                    maxRes = max(ans, maxRes);
                }

        cout << maxRes << endl;
    }
   

}

