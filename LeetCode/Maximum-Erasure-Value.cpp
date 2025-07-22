class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> numbersInWindow;
        int curSum = 0;
        int maxSum = 0;
        int l = 0;
        for(int r = 0 ; r < n; r++){
            while(l <= r && numbersInWindow.count(nums[r])){
                curSum -= nums[l];
                numbersInWindow.erase(nums[l++]);
            }
            curSum += nums[r];
            numbersInWindow.insert(nums[r]);
            maxSum = max(maxSum,curSum);
        }
        return maxSum;
    }
};