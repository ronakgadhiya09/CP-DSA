class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int l = 0;
        long long ans = 0;
        long long curSum = 0;
        for(int r = 0 ; r < n ; r++){
            curSum += nums[r];
            while(l <= r && curSum*(r-l+1) >= k){
                curSum -= nums[l];
                l++;
            }

            ans += (r-l+1);
        }
        return ans;
    }
};