class Solution {
public:
    int n, k;
    static constexpr int MAXN = 20000;
    long long dp[MAXN][2];

    long long dfs(int index, bool xorApplied, const vector<int>& nums) {
        if (index == n)
            return xorApplied ? LLONG_MIN : 0;

        if (dp[index][xorApplied] != -1)
            return dp[index][xorApplied];

        long long normal = nums[index] + dfs(index + 1, xorApplied, nums);
        long long withXor = (nums[index] ^ k) + dfs(index + 1, !xorApplied, nums);

        return dp[index][xorApplied] = max(normal, withXor);
    }

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        this->n = nums.size();
        this->k = k;

        memset(dp, -1, sizeof(dp));

        return dfs(0, false, nums);
    }
};
