class Solution {
    bool dfs(int &i, vector<vector<int>> &graph, vector<int> &v){
        if(v[i]==2){
            return true;
        }
        if(v[i]==1){
            return false;
        }
        v[i]=1;
        for(auto j: graph[i]){
            if(dfs(j,graph,v)==false){
                return false;
            }
        }
        v[i]=2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> v(n,0);
        vector<int> res;
        for(int i=0;i<n;i++){
            if(dfs(i,graph,v)==true){
                res.push_back(i);
            }
        }
        return res;
    }
};