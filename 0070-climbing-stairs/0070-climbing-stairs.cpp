class Solution {
    int helper(int n, vector<int>& dp){
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        else{
            return dp[n]=helper(n-1,dp)+helper(n-2,dp);
        }
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};