class Solution:
    def climbStairs(self, n: int) -> int:
        memo_table = {1:1,0:1}
        def calculate(k,memo_table):
            if k in memo_table:
                return memo_table[k]
            value = calculate(k-1,memo_table)+calculate(k-2,memo_table)
            memo_table[k]=value 
            return value      
        return calculate(n,memo_table)
    
    def climbStairs1(self, n: int) -> int:
        a = b = 1
        for _ in range(n):
            a, b = b, a + b
        return a
item  = Solution()
print(item.climbStairs1(8))