class Solution {
public:
    void solve(int n,int m,vector<string> &ans,string s){
        if(n==0&&m==0){
            ans.push_back(s);
            return;
        }
        if(n>0){
            s += "(";
            solve(n-1,m,ans,s);
            s.pop_back();
        }
        if(m>n){
            s += ")";
            solve(n,m-1,ans,s);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        solve(n,n,ans,str);
        return ans;
    }
};
