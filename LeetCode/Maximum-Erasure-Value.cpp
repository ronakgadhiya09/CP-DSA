class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(100001,0);
        int curSum = 0;
        int maxSum = 0;
        int l = 0;
        for(int r = 0 ; r < n; r++){
            while(l <= r && freq[nums[r]]){
                curSum -= nums[l];
                freq[nums[l++]]--;
            }
            curSum += nums[r];
            freq[nums[r]]++;
            maxSum = max(maxSum,curSum);
        }
        return maxSum;
    }
};