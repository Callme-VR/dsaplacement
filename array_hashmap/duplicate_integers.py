from typing import List

class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        hashset = set()

        for n in nums:
            if n in hashset:
                return True
            hashset.add(n)  

        return False
# ---- Taking input ----
nums = list(map(int, input("Enter numbers separated by comma: ").split(',')))

sol = Solution()
print(sol.hasDuplicate(nums))
