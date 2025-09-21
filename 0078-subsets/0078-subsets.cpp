class Solution {
    void solve(vector<int>nums,vector<int>output,int index,vector<vector<int>>& ans){
        //base case
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        //exclude
        solve(nums,output,index+1,ans);
        //include
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        solve(nums,output,index,ans);
        return ans;
    /*vector<vector<int>> res = {{}}; 
    for (int num : nums) {
        int n = res.size();
        for (int i = 0; i < n; ++i) {
            vector<int> subset = res[i];
            subset.push_back(num); 
            res.push_back(subset); 
        }
    }
    return res;*/
    
    }
};