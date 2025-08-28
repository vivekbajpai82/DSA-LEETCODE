class Solution1 {
public:
    // brute force n^2 TLE
    // 322/324
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) return 0;
        int total=0;
        for(int i=0;i<n;i++){
            int left=0;
            int right=0;
            for(int j=0;j<=i;j++){
                left=max(left,height[j]);
            }
            for(int j=i;j<n;j++){
                right=max(right,height[j]);
            }
            total+=min(left,right)-height[i];
        }
        return total;
    }
};
class Solution {
public:
    // optimised o(n)
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) return 0;
        int total=0;
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        for(int j=n-2;j>=0;j--){
            right[j]=max(right[j+1],height[j]);
        }
        for(int i=0;i<n;i++){
            total+=min(left[i],right[i])-height[i];
        }
        return total;
    }
};

