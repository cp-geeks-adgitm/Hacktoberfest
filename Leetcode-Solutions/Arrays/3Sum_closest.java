class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.length - 2; i++) {
            if (nums[i] + nums[nums.length - 2] + nums[nums.length - 1] < target) {
                ans = nums[i] + nums[nums.length - 2] + nums[nums.length - 1];
                continue;
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] > target) {
                if (nums[i] + nums[i + 1] + nums[i + 2] - target < Math.abs(target - ans))
                    ans = nums[i] + nums[i + 1] + nums[i + 2];
                break;
            }
            int l = i + 1, r = nums.length - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (Math.abs(target - ans) > Math.abs(sum - target))
                    ans = sum;
                if (sum == target)
                    return target;
                if (sum < target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
}