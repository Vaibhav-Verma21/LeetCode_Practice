class Solution:
    def longestSubsequence(self, nums: list[int]) -> int:
        n = len(nums)
        if all(x == 0 for x in nums):
            return 0
        
        total_xor = 0
        for x in nums:
            total_xor ^= x
            
        if total_xor != 0:
            return n
        else:
            return n - 1
