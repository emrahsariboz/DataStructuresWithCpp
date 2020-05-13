#include <iostream>

using namespace std;


void addEgde(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

void dfs(int node, vector<int> adj[], int dp[], bool visited[]){
    visited[node] = true;

    for (int i=0; i<adj[node].size(); i++){
        if(visited[adj[node][i] == false])
            dfs(adj[node][i], adj, dp, visited);

        dp[node]  = max(df[node], 1+ df[adj[node][i]]);
    }
}

int findLonPath(vector<int> adj[], int n){
    int dp[n+1];

    memset(dp, 0, sizeof dp);

    bool visited[n+1];
    membset(visited, false, sizeof visited);

    for (int i=1; i<=n; i++){
        if (visited[i] == false){
            dfs(i, adj, dp, visited);
        }
    }

    for (int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
    }
    return ans;
}



int main(){
 int n = 5; 
    vector<int> adj[n + 1]; 
  
    // Example-1 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 3, 2); 
    addEdge(adj, 2, 4); 
    addEdge(adj, 3, 4); 
  
    cout << findLongestPath(adj, n); 
    return 0; 
}