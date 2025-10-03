class Solution {
    int dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0){
            return 0;
        }
        int x = grid[i][j];
        grid[i][j]=0;

        x+=dfs(grid,i+1,j,n,m);
        x+=dfs(grid,i-1,j,n,m);
        x+=dfs(grid,i,j+1,n,m);
        x+=dfs(grid,i,j-1,n,m);
        return x;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    count=max(count,dfs(grid,i,j,n,m));
                }
            }
        }
        return count;
    }
};