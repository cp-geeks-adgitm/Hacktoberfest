# Problem link - https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

# Intution :-
# For each dice n, we need to consider k possible values
# and include the ones that equal to target
# We can avoid revisiting the same state by caching the results for tuple (n, target)

class Solution:
  def numRollsToTarget(self, n: int, k: int, target: int) -> int:
    dp = defaultdict(int)
    def dfs(n, k, target):
      # checks if already visited
      if (n, target) in dp: return dp[(n, target)]
      # no need to continue if target can't be achieved
      if target < 0: return 0
      if n == 0: return 1 if target == 0 else 0
      ways = 0
      for i in range(1, k + 1):
        # for a given dice, check for all k possibilites
        ways += dfs(n - 1, k, target - i)
      # cache the result 
      dp[(n, target)] = ways
      return ways % (10 ** 9 + 7)
    return dfs(n, k, target)
