class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1); // Length of the longest divisible subset ending at each index
        vector<int> prev(n, -1); // To keep track of previous index in the subset

        int maxi = 1; // Length of the largest subset found
        int ind = 0; // Index of the last element in the largest subset

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                ind = i;
            }
        }

        vector<int> ans;
        while (ind != -1) {
            ans.push_back(nums[ind]);
            ind = prev[ind];
        }

        // reverse(ans.begin(), ans.end());
        return ans;
    }
};
