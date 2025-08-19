class Solution1 {
    //TLE
    int helper(int n,int m,vector<vector<int>>& grid){
        if(n==0 && m==0) return grid[0][0];
        if(n<0 || m<0) return INT_MAX;

        return grid[n][m]+min(helper(n-1,m,grid),helper(n,m-1,grid));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        return helper(n-1,m-1,grid);
    }
};

class Solution {
    int helper(int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(n==0 && m==0) return grid[0][0];
        if(n<0 || m<0) return INT_MAX;
        if(dp[n][m]!=-1) return dp[n][m];
        return dp[n][m]=grid[n][m]+min(helper(n-1,m,grid,dp),helper(n,m-1,grid,dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,grid,dp);
    }
};


