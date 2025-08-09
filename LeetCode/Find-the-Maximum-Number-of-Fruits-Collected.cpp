class Solution {
private:
    bool check(int x,int y,int n){
        if(x >= 0 && x < n && y >= 0 && y < n) return true;
        return false;
    }

    int f(int x,int y,vector<vector<int>>& fruits,vector<vector<int>> &dp){
        int n = fruits.size();
        if(x==n-1 && y==n-1 || x == y) return 0;
        if(x==n-1) return INT_MIN;
        if(dp[x][y]!=-1) return dp[x][y];

        int best_fit = INT_MIN;
        for(int dy = -1 ; dy <= 1; dy++){
            if(check(x+1,y+dy,n))
                best_fit = max(best_fit,f(x+1,y+dy,fruits,dp));
        }

        return dp[x][y] = best_fit + fruits[x][y];
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {

        int n = fruits.size();

        long long ans = 0;
        for(int i = 0 ; i < n ;i++) ans += fruits[i][i];

        vector<vector<int>> dp(n,vector<int>(n,-1));

        ans += f(0,n-1,fruits,dp);

        for(int i = 0 ; i < n ;i++){
            for(int j = i  + 1 ; j < n ;j++){
                swap(fruits[i][j],fruits[j][i]);
            }
        }

        dp.assign(n,vector<int>(n,-1));
        ans += f(0,n-1,fruits,dp);
        
        return ans;
    }
};