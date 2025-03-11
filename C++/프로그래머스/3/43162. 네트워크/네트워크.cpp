#include <string>
#include <vector>

using namespace std;

vector<int> adj[205];
int g[205];
int m;

void dfs(int u, int gnum) {
    g[u] = gnum;
    for(auto v:adj[u]){
        if(g[v]) continue;
        dfs(v, gnum);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i!=j && computers[i][j]==1) {
                adj[i+1].push_back(j+1);
            }
        }
    }
    
    m = n;
    int gnum = 0;
    for(int i=1; i<=m; i++) {
        if(g[i]==0) {
            dfs(i, ++gnum);
        }
    }
    
    answer = gnum;
    
    return answer;
}