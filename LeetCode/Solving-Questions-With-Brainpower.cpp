class Solution {
private:
    long long f(int index,vector<vector<int>>& questions, vector<long long> &dp){

        int n = questions.size();
        if(index >= n) return 0;

        if(dp[index]!=-1){
            return dp[index];
        }
            

        int curPoint = questions[index][0];
        int brainNeeded = questions[index][1];

        long long take = curPoint + f(index+brainNeeded + 1,questions,dp);
        long long notTake = f(index+1,questions,dp);

        return dp[index] = max(take,notTake);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return f(0,questions,dp);
    }
};