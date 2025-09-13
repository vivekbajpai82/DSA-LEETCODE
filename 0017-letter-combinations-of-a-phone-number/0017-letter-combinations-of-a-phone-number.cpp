class Solution {
public:
    vector<string> res;
    vector<string> v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void helper(string &digits,int i,string curr){
        if(i==digits.size()){
            res.push_back(curr);
            return;
        }
        string lett=v[digits[i]-'0'];
        for(auto j : lett){
            helper(digits,i+1,curr+j);
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        helper(digits,0,"");
        return res;
    }
};