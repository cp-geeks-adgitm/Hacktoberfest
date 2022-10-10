import math
# Function to find the maximum sum of a subarray(elements not to be re-arranged)
def maxSumSubArray(arr):
    maxSum = 0  
    curSum = 0

    # maxSum = -math.inf   if it is not sure that no case where all numbers are negative
    # curSum = -math.inf

    for i in range(len(arr)):

        if i!=0:
            curSum += arr[i]
        else:
            curSum = arr[0]

        if(curSum>maxSum):
            maxSum = curSum

        if(curSum<0):
            curSum=0

    return(maxSum)

print(maxSumSubArray([-1,-8,-3,-4,-100]))