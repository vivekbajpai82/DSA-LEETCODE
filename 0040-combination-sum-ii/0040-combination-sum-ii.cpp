#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int start, vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            // skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            path.push_back(candidates[i]);
            backtrack(i + 1, candidates, target - candidates[i], path, res);
            path.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(0, candidates, target, path, res);
        return res;
    }
};
