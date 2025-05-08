#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> bfs(int v, vector<int> adj[]){
    queue<int> q;
    int vis[v] = {0};
    vis[0] = 1;
    vector<int> ans;
    q.push(0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for( auto ele: adj[node]){
            if(!vis[ele]){
                vis[ele] = 1;
                q.push(ele);
            }
        }
    }

    return ans;
}
void addEdge(vector<int> adj[], int u, int v){
    cout<<"value u: "<<u<<"value v: "<<v<<"\n";
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<int> adj[6];
    addEdge(adj, 0,1);
    addEdge(adj, 1,2);
    addEdge(adj, 1,3);
    addEdge(adj, 0,4);
    
    vector<int> ans = bfs(5, adj);
    for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<"\t";
    }
return 0;
}