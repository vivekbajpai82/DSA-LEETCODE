class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()<word2.size()) return false;
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(auto i : word1) m1[i]++;
        for(auto j : word2) m2[j]++;
         for(auto i : m1){
            if(m2.find(i.first)==m2.end()){
                return false;
            }
         }
        vector<int> v1,v2;
        for(auto i : m1) v1.push_back(i.second);
        for(auto j : m2) v2.push_back(j.second);
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2;
    }
};