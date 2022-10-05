class Solution:

    # approach of finding palindrome from middle
    def longestPalindrome(self, s: str) -> str:
        res = ""

        # starting at l,r expand outwards to find the biggest palindrome
        def palindromeAt(s, l, r):    
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            return s[l+1:r]

        # iterating through each element
        for i in range(len(s)):        
            odd  = palindromeAt(s, i, i)
            even = palindromeAt(s, i, i+1)
            res = max(res, odd, even, key=len)
        return res
    
    # dp approach
    def longestPalindrome1(self, s):
        # initialize the dp matrix
        dp = [[False]*len(s) for _ in range(len(s)) ]

        # diagonal case / char is always palindrome
        for i in range(len(s)):
            dp[i][i]=True
        ans=s[0]
        for col in range(len(s)):
            for row in range(col):
                # filling the matrix top to diagonal down
                # * * * *
                #   * * *
                #     * *
                
                # used for checking the length 1 substr
                if s[row]==s[col] and (dp[row+1][col-1] or col==row+1):
                    dp[row][col]=True
                    if col-row+1>len(ans):
                        ans=s[row:col+1]
        return ans


item  = Solution()
print(item.longestPalindrome("aabaaba"))