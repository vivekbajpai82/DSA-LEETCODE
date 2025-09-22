class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> f(101,0);
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
        }
        int ans=0;
        int temp=0;
        for(int i=1;i<101;i++){
            if(f[i]==temp){
                ans+=f[i];
            } else if(f[i]>temp){
                ans = f[i];
                temp = f[i];
            }
        }
        return ans;
    }
};