#include <iostream>
#include <vector>
using namespace std;

const int N = 100000;

int n, m , res; vector<int>adj[N]; bool vis[N]; bool Meow [N];


bool isLeaf(int node) {


    if (adj[node].size() == 1 && node!=0) {
        return true;
    }

    return false;
}


void dfs(int node, int CatCount) {

    vis[node] = 1;

    if (Meow[node]) CatCount++;
    else CatCount = 0;
    if (CatCount > m) return;
    if (isLeaf(node)) res++;
   
   
    for (int i = 0; i < adj[node].size(); i++) {
        int nextNode = adj[node][i];
        if (!vis[nextNode]) dfs(nextNode, CatCount);
    }


}



int main() {

    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> Meow[i];
    }

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, 0);
    cout << res << endl;

    return 0;
}
