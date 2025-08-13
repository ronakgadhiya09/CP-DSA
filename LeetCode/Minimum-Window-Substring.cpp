class Solution {
public:
    string minWindow(string s, string t) {
        // frequency arrays for ASCII letters
        vector<int> need(128, 0), window(128, 0);
        for(char c : t) need[(int)c]++;

        int required = 0;
        for(int i = 0; i < 128; ++i) if(need[i] > 0) required++;

        int formed = 0;
        int l = 0, r = 0;
        int bestLen = INT_MAX, bestL = 0;

        while(r < s.length()) {
            char cr = s[r];
            window[(int)cr]++;
            if(window[(int)cr] == need[(int)cr]) ++formed;

            // try to contract while all required chars are satisfied
            while(l <= r && formed == required) {
                if(r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestL = l;
                }
                char cl = s[l];
                window[(int)cl]--;
                if(window[(int)cl] < need[(int)cl]) --formed;
                l++;
            }
            r++;
        }

        return (bestLen == INT_MAX) ? string("") : s.substr(bestL, bestLen);
    }
};
