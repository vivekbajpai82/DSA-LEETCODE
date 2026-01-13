class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        
        unordered_map<int, int> freq;
        
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> s3(nums3.begin(), nums3.end());
        
        for (int x : s1) freq[x]++;
        for (int x : s2) freq[x]++;
        for (int x : s3) freq[x]++;
        
        vector<int> ans;
        for (auto it : freq) {
            if (it.second >= 2) {
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};
