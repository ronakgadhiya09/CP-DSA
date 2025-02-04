class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:

        temp = nums[0]
        maxi = nums[0]
        n = len(nums)

        for i in range(1,n):
            if nums[i-1] < nums[i]:
                temp += nums[i]
            else:
                temp = nums[i]
            maxi = max(maxi,temp)

        return maxi
