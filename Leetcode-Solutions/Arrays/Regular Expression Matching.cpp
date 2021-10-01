class Solution {
public:
    int dp[21][31];
    int solve(int i, int j, string &s, string &p) // i for s and j for p
    {
        if(i<0 || j<0)return 0;
        if(i==0 && j==0)return 1; // if both empty
        if(j==0 && i)return 0; // if p is empty return false
        if(i==0 && j) // if s is empty
        {
            // required pattern for answer to be true is _*_*_* (where _ can be replaced with any character)
			if(j%2)return 0; // does not match the pattern
            for(int k=1;k<j;k+=2)
            {
                if(p[k]!='*')return 0;
            }
            
            return 1; // if everyting satisfies
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(p[j-1]=='.')
        {
            return dp[i][j]=solve(i-1,j-1,s,p); // replace '.' with s[i-1] and continue to solve further.
        }
        
        if(p[j-1]=='*')
        {
            int ans=solve(i,j-2,s,p); // zero repetitions of preceding character
            char c=p[j-2];
            for(int k=i;k>=1;k--)
            {
                if(s[k-1]==c || c=='.') // till the character 'c' matches characters in 's' or if c is '.'                 {
                    ans= (ans | solve(k-1,j-2,s,p));
                }
                else break;
            }
            return dp[i][j]=ans;
        }
        if(p[j-1]==s[i-1])return dp[i][j]=solve(i-1,j-1,s,p);
        return dp[i][j]=0;
        
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(s.size(),p.size(),s,p);
        
    }
};
