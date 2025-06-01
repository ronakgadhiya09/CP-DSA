class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long total = 0;
        for(int i = 0; i <= min(limit,n); i++){
            if(n > i + 2*limit) continue;
            total += min(n-i,limit) + 1;
            long long sub = n - i - limit;
            sub = max(sub,0LL);
            total -= sub;
        }
        
        return total;
    }
};