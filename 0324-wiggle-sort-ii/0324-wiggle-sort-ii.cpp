class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v(nums);
        sort(v.begin(),v.end());
        int n=nums.size();
        int mid=(n+1)/2;
        int j=mid-1;
        int k=n-1;
        for(int i=0;i<n;i++){
            nums[i]=(i%2==0) ? v[j--]:v[k--];
        }
    }
};