class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if(s.size() != goal.size()) return false;

        // case 1: already same
        if(s == goal){
            vector<int> freq(26,0);
            for(char c : s){
                freq[c-'a']++;
                if(freq[c-'a'] > 1)
                    return true;
            }
            return false;
        }

        // case 2: not same
        int first = -1, second = -1;

        for(int i = 0; i < s.size(); i++){
            if(s[i] != goal[i]){
                if(first == -1) first = i;
                else if(second == -1) second = i;
                else return false; // more than 2 diff
            }
        }

        if(second == -1) return false;

        return s[first] == goal[second] &&
               s[second] == goal[first];
    }
};
