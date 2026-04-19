class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int x=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(colors[i]!=colors[j])
                x = max(x,abs(i-j));
            }
        }
        return x;
    }
};