class Solution {
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int source, int destination){
        if(source == destination){
            return true;
        }
        visited[source]=1;
        for(int i : graph[source]){
            if(!visited[i]){
                if(dfs(graph,visited,i,destination)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n,0);
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(graph,visited,source,destination);
    }
};

