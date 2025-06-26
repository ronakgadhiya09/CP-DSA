class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sm = 0;
        int cnt = 0;
        int bits = 32 - __builtin_clz(k);
        int n = s.size();

        for (int i = 0; i < n; i++){
            char ch = s[n - i - 1];
            if (ch == '1'){
                if (i < bits && sm + (1 << i) <= k){
                    sm += 1 << i;
                    cnt++;
                }
            } 
            else{
                cnt++;
            }
        }

        return cnt;
    }
};