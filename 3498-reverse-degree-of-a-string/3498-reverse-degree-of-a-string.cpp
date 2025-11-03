class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int d=0;
        for(int i=1;i<=n;i++){
            int m=123-s[i-1];
            d+=m*i;
        }
        return d;
    }
};