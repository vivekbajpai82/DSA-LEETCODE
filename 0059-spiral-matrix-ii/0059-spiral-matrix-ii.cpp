class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>>matrix(n, vector<int>(n));
        int m = matrix.size();
        int x = matrix[0].size();
        int srow=0;
        int scol=0;
        int erow=m-1;
        int ecol=x-1;
        int num=1;
        while(srow<=erow && scol<=ecol){
            for(int j=scol;j<=ecol;j++){
                matrix[srow][j]=num++;
            }
            for(int i=srow+1;i<=erow;i++){
                matrix[i][ecol]=num++;
            }
            for(int j=ecol-1;j>=scol;j--){
                if(srow==erow){
                    break;
                }
                matrix[erow][j]=num++;
            }
            for(int i=erow-1;i>=srow+1;i--){
                if(scol==ecol){
                    break;
                }
                matrix[i][scol]=num++;
            }
            srow++;
            scol++;
            erow--;
            ecol--;

        }
        return matrix;
    }
};