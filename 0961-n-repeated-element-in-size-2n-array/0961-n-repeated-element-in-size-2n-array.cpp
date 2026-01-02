class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        std::unordered_map<int ,int> mp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[i+1]){
                return nums[i];
            }
        }
        //int c;
        /*for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]>0)
                return nums[i];
            mp[nums[i]]++;    
        }
       /*- for(int i=0;i<nums.size();i++){
            if(mp.first()==mp.second()){
                c++;
            }
        }*/
        return 0;
    }
};