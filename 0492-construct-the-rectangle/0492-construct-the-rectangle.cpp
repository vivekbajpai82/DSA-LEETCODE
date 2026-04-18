class Solution {
public:
    vector<int> constructRectangle(int area) {
        int i = sqrt(area);
        while(i>=1){
            if(area%i==0){
                int w=i;
                int l=area/i;
                return {l,w};
            }
            i--;
        }
        return {};   
    }
};