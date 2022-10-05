n = int(input())
elements = input().split()
# i[::-1] reverse the string
# any(i==i[::-1]) check palindrome by reversing and checking the element
print(all(int(i) > 0 for i in elements) and any(i == i[::-1] for i in elements))