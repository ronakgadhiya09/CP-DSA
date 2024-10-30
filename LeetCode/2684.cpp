class Solution {

private:
    int m;
    int n;
    int waysToMove(int row,int column,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(column==n-1) return 0;
        if(dp[row][column]!=-1) return dp[row][column];
        int up = 0;
        int same = 0;
        int down = 0;
        if(row-1>=0 && column+1<n && (grid[row-1][column+1] > grid[row][column])){
            up = 1 + waysToMove(row-1,column+1,grid,dp);
        }
        if(column+1<n && (grid[row][column+1] > grid[row][column])){
            same = 1 + waysToMove(row,column+1,grid,dp);
        }
        if(row+1<m && column+1<n && (grid[row+1][column+1] > grid[row][column])){
            down = 1 + waysToMove(row+1,column+1,grid,dp);
        }

        return dp[row][column] = max({up,down,same});
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxi = 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i = m - 1 ; i >= 0 ; i--){
            maxi = max(maxi,waysToMove(i,0,grid,dp));
            if(maxi==n-1) return maxi;
        }

        return maxi;
    }
};
