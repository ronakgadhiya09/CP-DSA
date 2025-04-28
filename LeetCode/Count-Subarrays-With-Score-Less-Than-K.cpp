class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size();
        long long l = 0;
        long long ans = 0;
        long long curSum = 0;
        for(long long r = 0 ; r < n ; r++){
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