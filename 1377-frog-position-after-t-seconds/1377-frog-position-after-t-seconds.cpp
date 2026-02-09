class Solution {
    double ans = 0.0;

    void dfs(int src,vector<vector<int>>& adj,vector<int>& vis,int t,int target,double prob) {
        vis[src] = 1;
        if (t == 0) {
            if (src == target) ans = prob;
            return;
        }

        int children = 0;
        for (auto next : adj[src]) {
            if (!vis[next]) children++;
        }
        if (children == 0) {
            if (src == target) ans = prob;
            return;
        }

        for (auto next : adj[src]) {
            if (!vis[next]) {
                dfs(next, adj, vis, t - 1, target, prob / children);
            }
        }
        vis[src] = 0;
    }

public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {

        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n + 1, 0);

        dfs(1, adj, vis, t, target, 1.0);

        return ans;
    }
};
