class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        map<int,int> dp;
        int ans = 1;
        for(auto &num : nums){
            if(dp.find(num)!=dp.end()) continue;
            int sq = sqrt(num);
            if(sq*sq==num && dp.find(sq)!=dp.end()){
                dp[num] = 1 + dp[sq];
            }
            else{
                dp[num] = 1;
            }
            ans = max(ans,dp[num]);
        }

        if(ans==1) return -1;
        return ans;
    }
};
