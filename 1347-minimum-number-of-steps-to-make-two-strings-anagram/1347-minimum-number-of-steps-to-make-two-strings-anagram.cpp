class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(auto i : s) m1[i]++;
        for(auto j : t) m2[j]++;
        int steps=0;
        for(auto i : m1){
            char x=i.first;
            int y=i.second;
            int z=m2[x];
            if(y>z){
                steps+=(y-z);
            }
        }
        return steps;
    }
};