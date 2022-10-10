class Solution {
public:
    bool dfs(vector<int> graph[], bool recur[],int p, bool vis[]){
        recur[p] = true;
        vis[p] = true;
        
        for(auto it : graph[p]){
            if(recur[it])
                return false;
            if(!vis[it] && !dfs(graph,recur,it,vis)){
                return false;
            }
        }
        
        recur[p] = false;
        
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        
        for(auto it : prerequisites){
            graph[it[0]].push_back(it[1]);
        }
        
        bool recur[numCourses];
        memset(recur,false,sizeof(recur));
        bool vis[numCourses];
        memset(vis,false,sizeof(vis));
        
        for(int i=0;i<numCourses; i++){
            if(!vis[i])
                if(!dfs(graph,recur,i,vis))
                    return false;
        }
        return true;
    }
};