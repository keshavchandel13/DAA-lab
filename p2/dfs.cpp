#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<int>adj[], vector<bool>&vis, vector<int>&ans, int start){
     vis[start] = true;
     ans.push_back(start);
     for(auto node : adj[start]){
        if(!vis[node]){

            dfs(adj, vis, ans, node);
        }
     }
}
void addEdge(vector<int>adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<int> adj[6];
    vector<bool> vis(6,false);
    vector<int>  ans;
    addEdge(adj, 0,1);
    addEdge(adj, 1,2);
    addEdge(adj, 1,3);
    addEdge(adj, 0,4);
    dfs(adj, vis, ans, 0 );
    for(auto i : ans){
        cout<<i<<" ";
    }

return 0;
}
