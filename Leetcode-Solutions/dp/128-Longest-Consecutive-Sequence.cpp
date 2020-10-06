//Contributed By : Rishabh Jain

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
    unordered_map<int,int> h;
        
    int maxLength = 0;
        
    for(int i=0;i<nums.size();i++){
            
        int n = nums[i];
            
        if(!h.count(n)){

            int left = h.count(n-1)==1 ? h[n-1] : 0;
            int right = h.count(n+1)==1 ? h[n+1] : 0;

            int sum = left + 1 + right;

            maxLength = max(maxLength,sum);
            
            h[n] = sum;

            h[n-left] = sum;
            h[n+right] = sum;
        }
    }
        
    return maxLength;
}
};