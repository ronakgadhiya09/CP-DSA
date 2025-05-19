class Solution {
private:
    bool helper(string &s1, string &s2, int i, int j, int len,
                            vector<vector<vector<int>>> &dp) {
        if (dp[i][j][len] != -1) {
            return dp[i][j][len];
        }
        if (len == 1) {
            return dp[i][j][len] = s1[i] == s2[j];
        }
        for (int k = 1; k < len; k++) {
            if (helper(s1, s2, i, j, k, dp) && helper(s1, s2, i + k, j + k, len - k, dp)) {
                return dp[i][j][len] = true;
            }
            if (helper(s1, s2, i, j + len - k, k, dp) && helper(s1, s2, i + k, j, len - k, dp)) {
                return dp[i][j][len] = true;
            }
        }
        return dp[i][j][len] = false;;
    }

public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return helper(s1,s2,0,0,n,dp);
    }
};
