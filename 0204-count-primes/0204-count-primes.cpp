class Solution {
public:
    int countPrimes(int n) {
        //sieve of eratosthenes
        vector<int> isprime(n+1,true);
        int ans=0;
        for(int i=2;i<n;i++){
            if(isprime[i]){
                ans++;
                for(int j=i*2;j<n;j=j+i){
                    isprime[j]=false;
                }
            }
        }
        return ans;
    }
};