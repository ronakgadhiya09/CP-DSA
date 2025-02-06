class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        
        freq = defaultdict(int)
        n = len(nums)

        for i in range(n):
            for j in range(i+1, n):
                freq[nums[i] * nums[j]] += 1
        
        ans = 0
        for product, f in freq.items():
            if f > 1:
                ans += (f * (f - 1)) * 4
        
        return ans
