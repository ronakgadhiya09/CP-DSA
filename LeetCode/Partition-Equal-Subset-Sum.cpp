class Solution {

private:
    bool targetSum(int index,vector<int>& nums,int target,vector<vector<int>> &dp){
        int n = nums.size();
        if(target==0) return true;
        if(target < 0 ) return false;
        else if(index==n) return false;
        if(dp[index][target]!=-1) return dp[index][target];
        bool taken = targetSum(index+1,nums,target-nums[index],dp);
        bool not_taken = targetSum(index+1,nums,target,dp);

        return dp[index][target] = taken|not_taken;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        int tar = sum/2;
        vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        return targetSum(0,nums,tar,dp);
    }
};