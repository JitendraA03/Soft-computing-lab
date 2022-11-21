#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, int src ){
    queue<int> q;
    vector<bool> vis(adj.size(), false);
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = true;
            }
        }
    }
}

void dfs(vector<vector<int>> &adj, int src, vector<bool> &vis){
    vis[src] = true;
    cout<<src<<" ";
    for(auto it : adj[src]){
        if(!vis[it]){
            dfs(adj, it, vis);
        }
    }
}

void limited_depth_dfs(vector<vector<int>> &adj, int src, vector<int> &vis, int depth){
    if(depth <= 0) return;

    if(vis[src] == -1) cout<<src<<" ";
    vis[src] = max(vis[src], depth);
    for(auto it : adj[src]){
        if(vis[it] < depth - 1){
            limited_depth_dfs(adj, it, vis, depth - 1);
        }
    }
}


void iterative_deepning(vector<vector<int>> &adj, int src){
    for(int i=1; i<=5; i++){
        cout<<"Iteration number : "<<i<<" \n";
        vector<int> vis(adj.size(), -1);
        limited_depth_dfs(adj, src, vis, i);

        cout<<"-----------------------------\n";
    }


}

int main(){
    
    return 0;
}