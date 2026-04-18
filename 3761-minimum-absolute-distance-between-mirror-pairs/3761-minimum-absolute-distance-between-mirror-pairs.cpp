class Solution {
public:
    int reverseNumber(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (mp.find(x) != mp.end()) {
                ans = min(ans, i - mp[x]);
            }
            mp[reverseNumber(x)] = i;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};