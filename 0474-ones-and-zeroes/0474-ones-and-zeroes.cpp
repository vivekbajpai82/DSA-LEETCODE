class Solution1 {//TLE REC
    vector<int> count(string &str1){
        int z=0;
        int o=0;
        for(char ch : str1){
            if(ch=='0') z++;
            if(ch=='1') o++; 
        }
        return {z,o};
    }
    int helper(vector<string>& strs,int index ,int m,int n){
        if(index<0) return 0;
        vector<int> c=count(strs[index]);

        int nottake=0+helper(strs,index-1,m,n);


        int take=0;
        if(m>=c[0] && n>=c[1]){
            take=1+helper(strs,index-1,m-c[0],n-c[1]);
        }
        return max(take,nottake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int x=strs.size();
        return helper(strs,x-1,m,n);
    }
};

class Solution2 {//REC+MEMO
    vector<int> count(string &str1){
        int z=0;
        int o=0;
        for(char ch : str1){
            if(ch=='0') z++;
            if(ch=='1') o++; 
        }
        return {z,o};
    }
    int helper(vector<string>& strs,int index ,int m,int n,vector<vector<vector<int>>> &dp){
        if(index<0) return 0;
        if (dp[index][m][n] != -1) return dp[index][m][n];

        vector<int> c=count(strs[index]);

        int nottake=0+helper(strs,index-1,m,n,dp);


        int take=0;
        if(m>=c[0] && n>=c[1]){
            take=1+helper(strs,index-1,m-c[0],n-c[1],dp);
        }
        return dp[index][m][n]=max(take,nottake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int x=strs.size();
        vector<vector<vector<int>>> dp(x, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return helper(strs,x-1,m,n,dp);
    }
};

	class Solution { //TABULATION
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (const string& str : strs) {
            int zeros = 0, ones = 0;
            for (char ch : str) {
                if (ch == '0') zeros++;
                else ones++;
            }

            for (int i=m; i>=zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j]=max(dp[i][j], 1+dp[i-zeros][j-ones]);
                }
            }
        }

        return dp[m][n];
    }
};


