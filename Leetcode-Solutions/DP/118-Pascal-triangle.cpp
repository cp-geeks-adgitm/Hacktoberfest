class Solution {
public:
    vector<vector<int>> generate(int numsRows) {
     
        vector<vector<unsigned>> dp(numsRows,vector<unsigned>(numsRows,0));
        vector<vector<int>> sol;
        
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp.size();j++)
            {
                if(i==0 or j==0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        for(int g=0;g<numsRows;g++)
        {
            vector<int> temp;
            for(int i=0,j=g;j>=0;j--,i++)
                temp.push_back(dp[i][j]);
            sol.push_back(temp);
        }
        
        return sol;
        
    }
};