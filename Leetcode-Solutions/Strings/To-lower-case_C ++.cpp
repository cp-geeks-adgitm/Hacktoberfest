class Solution {
public:
     string toLowerCase(string str) {
        int n=str.length();
        for(int i=0;i<n;i++){
         str[i]=tolower(str[i]);
        }
        return str;
    }
};
