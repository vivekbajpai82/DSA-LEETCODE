class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> v;
        unordered_map<int,int> mp;
        for(auto num : nums){
            mp[num]++;
        }
        for(auto i : mp){
            if(i.second==2){
                v.push_back(i.first);
            }
        }
        return v;
    }
};