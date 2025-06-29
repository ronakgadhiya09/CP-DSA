class Solution:
    def binarySearchRightmost(self, nums, target):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1
        return left

    def numSubseq(self, nums, target):
        n = len(nums)
        mod = 10**9 + 7
        nums.sort()

        power = [1] * n
        for i in range(1, n):
            power[i] = (power[i - 1] * 2) % mod

        answer = 0
        for left in range(n):
            remaining = target - nums[left]
            right = self.binarySearchRightmost(nums, remaining) - 1
            if left <= right:
                answer = (answer + power[right - left]) % mod

        return answer