class Solution {
public:
    bool hasAlternatingBits(int n) {
        string binary = "";
        while(n > 0) {
            binary = char((n % 2) + '0') + binary;
            n /= 2;
        }
        for(int i=0;i<binary.size();i++){
            if(binary[i]==binary[i+1]){
                return false;
            }
        }
        return true;
    }
};