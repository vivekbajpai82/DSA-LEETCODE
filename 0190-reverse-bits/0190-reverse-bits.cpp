class Solution {
public:
    int reverseBits(int n) {
      vector<int> v(32,0);int ans=0;  
      for(int i=31;i>=0;i--){
        int b = (n>>i)&1;v[i]=b;
      }
      for(int i=31;i>=0;i--){
        ans+=v[31-i]*(1<<i);
      } 
      return ans;
    }
};