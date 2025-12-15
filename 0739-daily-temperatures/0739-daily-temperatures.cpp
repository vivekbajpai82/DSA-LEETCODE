class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> v;

        for (int i = 0; i < n; i++) {
            int ans = 0;   
            for (int j = i + 1; j < n; j++) {
                if (temperatures[j] > temperatures[i]) {
                    ans = j - i;
                    break;   
                }
            }
            v.push_back(ans);
        }
        return v;
    }
};
