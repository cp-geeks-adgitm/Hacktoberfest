class Solution:
    def searchRange(self, nums, target):
        # we are using the binary search to get the index in O(logN) time
        left,right = 0,len(nums)-1
        while right>=left:
            mid = left +(right-left)//2
            if nums[mid]>target:
                right = mid-1
            elif nums[mid]<target:
                left = mid+1
            else:
                # IF we found the index
                leftest_index = rightest_index = mid

                # first occurence / first item index
                while leftest_index >0 and nums[leftest_index]==nums[leftest_index-1]:
                    leftest_index -=1

                # last item occurence
                while rightest_index<len(nums)-1 and nums[rightest_index]==nums[rightest_index+1]:
                    rightest_index +=1
                return[leftest_index,rightest_index]
        return [-1,-1]
        

item  = Solution()
print(item.searchRange([-1,-1,0,1,1,1,18,9,9],1))