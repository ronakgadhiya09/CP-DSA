class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int lp = 0, rp = 0;
        int ans = 0;

        while (rp < n) {
            freq[s[rp] - 'a']++;

            while (*max_element(freq.begin(), freq.end()) >= k) {
                ans += n - rp;
                freq[s[lp] - 'a']--;
                lp++;
            }
            rp++;
        }

        return ans;
    }
};
