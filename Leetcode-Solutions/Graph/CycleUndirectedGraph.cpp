#include<bits/stdc++.h>

bool cycle(vector<int> graph[], int v,int par, bool vis[]){
    vis[v] = true;
    
    for(auto it : graph[v]){
        if(it != par && vis[it])
            return true;
        if(!vis[it] && cycle(graph,it,v,vis))
            return true;
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> graph[n];
    
    for(auto it : edges){
        graph[it[0] - 1].push_back(it[1] - 1);
        graph[it[1] - 1].push_back(it[0] - 1);
    }
    
    bool vis[n];
    memset(vis,false,sizeof(vis));
    
    for(int i = 0;i < n;i++){
        if(!vis[i] && cycle(graph,i,-1,vis)){
            return "Yes";
        }
    }
    
    return "No";
}