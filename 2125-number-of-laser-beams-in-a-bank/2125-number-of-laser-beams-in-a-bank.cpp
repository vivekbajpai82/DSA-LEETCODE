class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result=0;
        int pre=0;
        for(auto& row:bank){
            int curr=count(row.begin(),row.end(),'1');
            if(curr==0) continue;
            result+=(pre*curr);
            pre=curr;
        }
        return result;
    }
};