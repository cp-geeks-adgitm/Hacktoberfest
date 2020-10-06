//Contributed By : Rishabh Jain

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        else if(nums.size()==1)
        {
            return nums[0];
        }
        else if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        int firstchoice=nums[0];
        int secondchoice=max(nums[0],nums[1]);int ans;
        for(int i=2;i<nums.size();i++)
        {
            ans=max(firstchoice+nums[i],secondchoice);
            firstchoice=secondchoice;
            secondchoice=ans;
            
        }
            
        return ans;
        
        
        
        
    }
};