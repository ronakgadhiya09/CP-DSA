class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        int value = 0;
        int n = s.size();
        int bits = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[n - 1 - i];
            if (ch == '0') {
                count++;
            }else {
                if (i < 31 && value + (1 << i) <= k) {
                    value += 1 << i;
                    count++;
                }
            }
        }
        return count;
    }
};
