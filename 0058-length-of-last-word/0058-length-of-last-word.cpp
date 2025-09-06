class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        bool c=false;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                c=true;
                count++;
            }
            else if(c){
                break;
            }
        }
        return count;
    }
};