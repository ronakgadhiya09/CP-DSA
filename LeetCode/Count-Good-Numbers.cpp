class Solution {

private:
    int mod = 1e9 + 7;
    long long binpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = ((res)%mod *(a)%mod)%mod;
            a = ((a)%mod *(a)%mod)%mod;
            b >>= 1;
        }
        return res%mod;
    }

public:
    int countGoodNumbers(long long n) {

        // if(n==1) return 5;
        long long eveni = (n+1)/2;
        long long oddi = n/2;

        long long ans = ((binpow(5,eveni))%mod*(binpow(4,oddi)%mod))%mod;

        return ans;
    }
};