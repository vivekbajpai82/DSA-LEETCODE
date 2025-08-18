class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>v;
        int m = matrix.size();
        int n = matrix[0].size();
        int srow=0;
        int scol=0;
        int erow=m-1;
        int ecol=n-1;
        while(srow<=erow && scol<=ecol){
            for(int j=scol;j<=ecol;j++){
                v.push_back(matrix[srow][j]);
            }
            for(int i=srow+1;i<=erow;i++){
                v.push_back(matrix[i][ecol]);
            }
            for(int j=ecol-1;j>=scol;j--){
                if(srow==erow){
                    break;
                }
                v.push_back(matrix[erow][j]);
            }
            for(int i=erow-1;i>=srow+1;i--){
                if(scol==ecol){
                    break;
                }
                v.push_back(matrix[i][scol]);
            }
            srow++;
            scol++;
            erow--;
            ecol--;

        }
        return v;

    }
};