#user/bin/env python3

class Solution:
    # Str indexing
    def isPalindrome(self, x: int) -> bool:
        if x<0: return False
        if (str(x) == str(x)[::-1]): 
            return True
        else:
            return False
        
    # Math
    def isPalindrome(self, x: int) -> bool:
        if x<0: return False
        x_rev = 0
        x_orig = x
        while (x>0):
            x_rev = x_rev * 10 + (x%10)
            x//= 10
        if (x_orig == x_rev): return True
        else: return False
    
if __name__ == "__main__":
    sol = Solution()
    print(sol.isPalindrome(121))
    print(sol.isPalindrome(-121))
    print(sol.isPalindrome(10))