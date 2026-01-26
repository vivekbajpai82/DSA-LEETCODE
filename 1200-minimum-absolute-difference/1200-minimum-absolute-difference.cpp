class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int min=INT_MAX;
        vector<vector<int>> x;
        for(int i=1;i<arr.size();i++){
            int y=arr[i]-arr[i-1];
            if(y<min){
                min=y;
                x={};
                x.push_back({arr[i-1],arr[i]});
            } else if(y==min){
                x.push_back({arr[i-1],arr[i]});
            }
        }
        return x;
    }
};