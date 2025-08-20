class Solution1 { //TLE
    int helper(int i,int j,vector<vector<int>>& matrix){
        if(i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }
        if(matrix[i][j]==0) return 0;
        int right = helper(i,j+1,matrix);
        int below = helper(i+1,j,matrix);
        int diagonal = helper(i+1,j+1,matrix);

        return 1+min(right, min(diagonal,below));
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=helper(i,j,matrix);
            }
        }
        return ans;
    }
};

class Solution { //REC+MEMO
    int helper(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &memo){
        if(i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }
        if(matrix[i][j]==0) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int right = helper(i,j+1,matrix,memo);
        int below = helper(i+1,j,matrix,memo);
        int diagonal = helper(i+1,j+1,matrix,memo);

        return memo[i][j]=1+min(right, min(diagonal,below));
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> memo(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=helper(i,j,matrix,memo);
            }
        }
        return ans;
    }
};