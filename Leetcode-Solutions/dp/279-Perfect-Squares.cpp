//Contributed By : Rishabh Jain

class Solution {
public:
    int numSquares(int n) {
        
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=i;
            for(int j=1;j*j<=i;j++)
            {   
                int minvalue=dp[i-j*j]+1;
                dp[i]=min(dp[i],minvalue);
            }
        }
        return dp[n];
    }
};