class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int c=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    bool row=true;
                    bool col=true;

                    for(int k=0;k<m;k++){
                        if(k!=j && mat[i][k]==1){
                            row=false;
                            break;
                        }
                    }
                    for(int k=0;k<n;k++){
                        if(k!=i && mat[k][j]==1){
                            col=false;
                            break;
                        }
                    }
                    if(row && col){
                        c++;
                    }
                }
            }
        }
        return c;
    }
};