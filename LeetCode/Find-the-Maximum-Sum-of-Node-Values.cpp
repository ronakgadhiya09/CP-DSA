class Solution {
public:
    long long dfs(int index, bool xorApplied, const vector<int>& nums, int k, 
                                                    vector<vector<long long>>& dp) {
        if (index == nums.size())
            return xorApplied ? LLONG_MIN : 0;

        if (dp[index][xorApplied] != -1)
            return dp[index][xorApplied];

        long long normal = nums[index] + dfs(index + 1, xorApplied, nums, k, dp);
        long long withXor = (nums[index] ^ k) + dfs(index + 1, !xorApplied, nums, k, dp);

        return dp[index][xorApplied] = max(normal, withXor);
    }

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return dfs(0, false, nums, k, dp);
    }
};
