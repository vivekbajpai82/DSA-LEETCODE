class Solution {
public:
    int minSwaps(string s) {
        int balance=0;
        int imblance=0;
        for(char &ch : s){
            if(ch=='['){
                balance++;
            }else{
                balance--;
            }
            if(balance<0){
                imblance = max(imblance,-balance);
            }
        }
        return (imblance+1)/2;
    }
};