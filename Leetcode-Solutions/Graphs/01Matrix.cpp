class Solution {
public:
    class dpair{
        public:
        int x,y,val;
        dpair(int x,int y,int val){
            this->x=x;
            this->y=y;
            this->val=val;
        }
    };
    bool valid(int x,int y,int n,int m){
        if(x<0||y<0||x>=n||y>=m)
            return false;
        return true;
    }
    vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return {};
         int n=matrix.size(),m=matrix[0].size();
        if(m==0){
            vector<vector<int>>ans;
            return ans;
        }
        queue<dpair*>que;
        vector<vector<bool>>vis(n,vector<bool>(m,false));       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    vis[i][j]=true;
                    que.push(new dpair(i,j,0));
                }
            }
        }
        while(que.size()>0){
            dpair* top=que.front();
            que.pop();
            for(int d=0;d<4;d++){
                int x=top->x+dir[d][0];
                int y=top->y+dir[d][1];
                if(valid(x,y,n,m) && !vis[x][y]){
                    vis[x][y]=true;
                    matrix[x][y]=top->val+1;
                    que.push(new dpair(x,y,top->val+1));
                }
            }
        }
        return matrix;
    }
};