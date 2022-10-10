# Problem link - https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

# Intuition :-
# For a subarray of baloons with same color,
# we need to remove all the baloons except the one which takes the minimum time.

# Complexity
# Time - O(N)
# Space - O(1)

class Solution:
  def minCost(self, colors: str, neededTime: List[int]) -> int:
    min_time = 0
    total_time = 0
    max_time = 0
    for i in range(len(colors)):
      if i > 0 and colors[i] != colors[i - 1]:
        # for each group, minimum time to make rope colorful again is
        # total time - max time
        min_time += total_time - max_time
        total_time = 0
        max_time = 0
      total_time += neededTime[i] 
      max_time = max(max_time, neededTime[i])
    min_time += total_time - max_time
    return min_time
