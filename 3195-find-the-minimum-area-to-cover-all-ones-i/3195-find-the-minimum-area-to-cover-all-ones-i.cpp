class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        //int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        int min1=n;
        int mini2=m;
        int maxi1=0;
        int maxi2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    min1=min(min1,i);
                    maxi1=max(maxi1,i);
                    mini2=min(mini2,j);
                    maxi2=max(maxi2,j);
                }
            }
        }
        return (maxi1-min1+1)*(maxi2-mini2+1);
    }
};