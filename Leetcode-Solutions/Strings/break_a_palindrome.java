class Solution {
    public String breakPalindrome(String palindrome) {
        if(palindrome.length()==1) return ;
        char[] ch = palindrome.toCharArray();
        int n = palindrome.length()/2;
        for(int i=0;i<n;i++){
            if(ch[i]!='a'){
                ch[i] = 'a';
                return new String(ch);
            }
        }
        ch[ch.length-1]++;
        return new String(ch);
    }
}
