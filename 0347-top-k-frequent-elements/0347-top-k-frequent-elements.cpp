class Solution {
public:  //BRUTE
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        unordered_map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        vector<pair<int,int>> V;
        for(auto i : mp){
            V.push_back({i.first,i.second});
        }
        sort(V.begin(), V.end(), [](pair<int,int> &a, pair<int,int> &b){
            return a.second > b.second;
        });
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(V[i].first);
        }

        return res;
        
    }
};