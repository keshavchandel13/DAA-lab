#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<int> adj[], int size, int start){
    bool vis[size] = {false};
    queue <int> bf;
    vector<int> ans;
    bf.push(start);
    vis[start] = true;
    while(!bf.empty()){
        int node = bf.front();
        bf.pop();
        ans.push_back(node);
        for(auto ele: adj[node]){
            if(!vis[ele]){
                bf.push(ele);
                vis[ele] = true;
            }
        }
    }
    for(auto i : ans){
        cout<<i<<" ";
    }
}
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<int> adj[6];
    addEdge(adj, 0,1);
    addEdge(adj, 1,2);
    addEdge(adj, 1,3);
    addEdge(adj, 0,4);
    bfs(adj, 5, 0);
return 0;
}