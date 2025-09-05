class Solution1 { // TLE
    int helper(int i,int j, string s1, string s2){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(s1[i]==s2[j]) return helper(i-1,j-1,s1,s2);
        return 1+min(helper(i-1,j,s1,s2), min(helper(i,j-1,s1,s2), helper(i-1,j-1,s1,s2)));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return helper(n-1,m-1,word1,word2);
    }
};

class Solution { // rec+memo
    int helper(int i,int j, string s1, string s2,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=helper(i-1,j-1,s1,s2,dp);
        return dp[i][j]=1+min(helper(i-1,j,s1,s2,dp), min(helper(i,j-1,s1,s2,dp), helper(i-1,j-1,s1,s2,dp)));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return helper(n-1,m-1,word1,word2,dp);
    }
};









