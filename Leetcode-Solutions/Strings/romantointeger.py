#roman to integer

class Solution:
    def romanToInt(self, s: str) -> int:
        s1={"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        s2=0
        for i in range (len(s)):
                if i+1<len(s) and s1[s[i]]<s1[s[i+1]]:
                    s2-=s1[s[i]]
                else:
                    s2+=s1[s[i]]
        return s2