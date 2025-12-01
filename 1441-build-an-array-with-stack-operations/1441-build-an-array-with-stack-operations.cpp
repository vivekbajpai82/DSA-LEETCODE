class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> v;
        int current=1;
        for(int i=0;i<target.size();i++){
        while(current < target[i]){
            v.push_back("Push");
            v.push_back("Pop");
            current++;
        }
        v.push_back("Push");
        current++;
    }
        
        return v;
    }
};