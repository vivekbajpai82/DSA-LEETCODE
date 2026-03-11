class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        bitset<32> b(n);
        string x = b.to_string();
        int pos = x.find('1');   
        x = x.substr(pos);
        string str="";
        for(int i=0;i<x.size();i++){
            if(x[i]=='0'){
                str.push_back('1');
            }
            else{
                str.push_back('0');
            }
        }
        int decimal = stoi(str, nullptr, 2);
        return decimal;
    }
};