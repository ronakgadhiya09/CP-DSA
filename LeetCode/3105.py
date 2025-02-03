class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        
        n = len(nums)
        si = 1
        sd = 1
        msi = 1
        msd = 1

        for i in range(1,n):
            if nums[i-1] > nums[i]:
                si += 1
            else:
                si = 1
            if nums[i-1] < nums[i]:
                sd += 1
            else:
                sd = 1
            
            msi = max(si,msi)
            msd = max(sd,msd)

        return max(msi,msd)
