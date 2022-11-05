/* Author :  JaiSehgal007 */

/* House Robber Problem II from Leetcode */

/* Link to the Problem : https://leetcode.com/problems/house-robber-ii/ */

/* 

PROBLEM DESCRIPTION :

    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a 
    circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact 
    the police if two adjacent houses were broken into on the same night.
    Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
    
*/

/*

EXAMPLES TO THE PROBLEM :

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3

*/

/*------------------------------------SOLUTION-----------------------------------------*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return n?nums[0]:0;
        return max(robber(nums,0,n-2),robber(nums,1,n-1));
    }
    int robber(vector<int>nums,int l,int r){
        int curr=0,pre=0;
        for(int i=l;i<=r;i++){
            int temp=max(pre+nums[i],curr);
            pre=curr;
            curr=temp;
        }
        return curr;
    }
};

/* House Robber Problem III from Leetcode */

/* Link to the Problem : https://leetcode.com/problems/house-robber-iii/ */

/*

PROBLEM DESCRIPTION:

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will 
automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

*/

/*

EXAMPLES TO THE PROBLEM:

Example 1:


Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:


Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

*/

/*-------------------------------------SOLUTION---------------------------------------*/
class Solution {
public:
    int robber(TreeNode* root,int &l,int &r){
        if(!root)return 0;
        int ll=0,lr=0,rl=0,rr=0;
        l=robber(root->left,ll,lr);
        r=robber(root->right,rl,rr);

        return max(l+r,root->val+ll+lr+rl+rr);

    }
    int rob(TreeNode* root) {
        int l,r;
        return robber(root,l,r);
    }
};

