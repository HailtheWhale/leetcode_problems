#user/bin/env python3

from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Make a hashmap.
        seen = {}
        for i,num in enumerate(nums):
            # The other number looking for.
            diff = target - num
            if diff in seen:
                return [seen[diff], i]
            seen[num] = i


if __name__ == "__main__":    
    s = Solution()
    print(s.twoSum([2,7,11,15], 9))
    print(s.twoSum([3,2,4], 6))
    print(s.twoSum([3,3], 6))