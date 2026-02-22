class Solution {
public:
    int binaryGap(int n) {
        bitset<32> b(n);
        
        int prev = -1;
        int ans = 0;
        
        for(int i = 0; i < 32; i++){
            if(b[i] == 1){
                if(prev != -1){
                    ans = max(ans, i - prev);
                }
                prev = i;
            }
        }
        
        return ans;
    }
};