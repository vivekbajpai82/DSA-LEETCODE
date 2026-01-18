class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> m1,m2;
        string word;
        stringstream x(s1);
        while(x>>word){
            m1[word]++;
        }
        stringstream y(s2);
        while(y>>word){
            m2[word]++;
        }
        vector<string> v;
        for(auto i : m1){
            if(i.second==1 && m2.find(i.first)==m2.end()){
                v.push_back(i.first);
            }
        }
        for(auto i : m2){
            if(i.second==1 && m1.find(i.first)==m1.end()){
                v.push_back(i.first);
            }
        }
        return v;
    }
};