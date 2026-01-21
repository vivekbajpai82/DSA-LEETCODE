class Solution {
    unordered_map<string,vector<int>> mp;
public:
    vector<int> diffWaysToCompute(string exp) {
        if(mp.count(exp)) return mp[exp];
        vector<int> ans;

        for(int i=0;i<exp.size();i++){
            char ch=exp[i];
            if(ch=='+' || ch=='-' || ch=='*'){
                vector<int> left=diffWaysToCompute(exp.substr(0,i));
                vector<int> right=diffWaysToCompute(exp.substr(i+1));
                for(int x : left){
                    for(int j : right){
                        if(ch=='+') ans.push_back(x+j);
                        else if(ch=='-') ans.push_back(x-j);
                        else ans.push_back(x*j);
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(exp));
        }
        return mp[exp] = ans;
        
    }
};
