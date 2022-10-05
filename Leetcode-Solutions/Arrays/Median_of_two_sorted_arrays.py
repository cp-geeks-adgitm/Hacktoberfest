class Solution:
    def findMedianSortedArrays(self, nums1, nums2) -> float:
        median_index = ((len(nums1)+len(nums2))//2)
        is_series_odd = (len(nums1)+len(nums2))%2==1
        i=j=0
        item=[]
        for _ in range(median_index+1):
            if i< len(nums1) and j<len(nums2):
                if nums1[i]<nums2[j]:
                    item.append(nums1[i])
                    i+=1
                else:
                    item.append(nums2[j])
                    j+=1
            elif i< len(nums1):
                item.append(nums1[i])
                i+=1
            else:
                item.append(nums2[j])
                j+=1
        return item[-1] if is_series_odd else (item[-1]+item[-2])/2


item  = Solution()
print(item.findMedianSortedArrays([1,3],[2,4]))