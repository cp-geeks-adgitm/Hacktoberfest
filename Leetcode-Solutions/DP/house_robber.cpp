/* Author : G Pala Venki Reddy */

/* House Robber Problem from Leetcode */

/* Link to the Problem : https://leetcode.com/problems/house-robber/ */

/* 
    Problem Description :

    You are a professional robber planning to rob houses along a street. 
    Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of 
    them is that adjacent houses have security system connected and it will automatically contact the police 
    if two adjacent houses were broken into on the same night. 

    Given an array of non-negative integers representing the amount of money of each house, determine the
    maximum amount of money you can rob tonight without alerting the police.

*/

/*
    Example 1:

    Input: [1,2,3,1]
    Output: 4
    Explanation: 
    Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.

    Example 2:

    Input: [2,7,9,3,1]
    Output: 12
    Explanation: 
    Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
    Total amount you can rob = 2 + 9 + 1 = 12.

*/

/* ------------------------------- Solution ------------------------------- */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        return dp[n];
    }
};


/* House Robber II Problem from Leetcode */

/* Link to the Problem : https://leetcode.com/problems/house-robber-ii/ */

/* 
    Problem Description :

    You are a professional robber planning to rob houses along a street. 
    Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
    That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security 
    system connected, and it will automatically contact the police if two adjacent houses were broken into 
    on the same night.

    Given an integer array nums representing the amount of money of each house, return the 
    maximum amount of money you can rob tonight without alerting the police.

*/

/*
    Example 1:

    Input: nums = [2,3,2]
    Output: 3
    Explanation: 
    You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

    Example 2:

    Input: nums = [1,2,3,1]
    Output: 4
    Explanation: 
    Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.

    Example 3:

    Input: nums = [1,2,3]
    Output: 3
    Explanation:
    You cannot rob house 1 (money = 1) and then rob house 3 (money = 3), because they are adjacent houses.

*/

/* ------------------------------- Solution ------------------------------- */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int dp[n+1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        int ans = dp[n-1];
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        ans = max(ans, dp[n]);
        return ans;
    }
};

