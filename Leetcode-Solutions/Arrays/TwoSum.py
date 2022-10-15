class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        array = {}

        for i in range(len(nums)):
            result = target-nums[i]
            if result in array:
                return [i, array[result]]
            else:
                array[nums[i]] = i
