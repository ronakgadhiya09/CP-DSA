class Solution {
public:
    long long minEnd(int k, int p) {

        long long n = k;
        long long x = p;
        vector<int> off_bits;
        for(int i = 0 ;i < 64;i++){
            if(!(x & (1LL<<i))) off_bits.push_back(i);
        }

        long long ans = x;

        int m = off_bits.size();
        n--;
        for(int i = m - 1 ; i >= 0 ;i--){
            if(n & (1LL<<i)){
                ans += (1LL<<off_bits[i]);
            }
        }

        return ans;
    }
};
