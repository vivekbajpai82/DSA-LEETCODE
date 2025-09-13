class Solution {
public:
    int maxFreqSum(string s) {
        int vol=0;
        int con=0;
        unordered_map<char,int> mp;
        for(auto i : s){
            mp[i]++;
        }
        for (auto i : mp) {
            if (i.first=='a'||i.first=='e'||i.first=='i'||i.first=='o'||i.first=='u') {
                vol = max(vol, i.second);
            } else {
                con = max(con, i.second);
            }
        }

        return vol + con;
    }
};