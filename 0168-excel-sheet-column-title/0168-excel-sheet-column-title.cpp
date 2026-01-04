class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str="";
        while(columnNumber>0){
            columnNumber--;
            char ch='A'+(columnNumber%26);
            str.push_back(ch);
            columnNumber /= 26;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};