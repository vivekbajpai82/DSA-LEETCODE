
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> m;
        int n = s.length();
        int l = 0;
        int r = 0;
        int max_len = 0;
        
        while (r < n) {
            if (m.find(s[r]) != m.end()) {
                l = std::max(l, m[s[r]] + 1);
            }
            int len = r - l + 1;
            max_len = std::max(len, max_len);
            m[s[r]] = r;
            r++;
        }
        
        return max_len;
    }
};