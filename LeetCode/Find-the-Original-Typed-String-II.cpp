class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int MOD = 1e9 + 7;

        vector<int> runs;
        for (size_t i = 0; i < word.size(); ) {
            size_t j = i;
            while (j < word.size() && word[j] == word[i]) ++j;
            runs.push_back(static_cast<int>(j - i));
            i = j;
        }

        long long total = 1;
        for (int len : runs) total = (total * len) % MOD;

        if (k == 1) return static_cast<int>(total);
        int R = static_cast<int>(runs.size());
        if (R >= k) return static_cast<int>(total);

        vector<int> dp(k, 0), nxt(k, 0);
        dp[0] = 1;                 

        for (int runIdx = 0; runIdx < R; runIdx++) {
            int window = min(runs[runIdx], k - 1);  
            fill(nxt.begin(), nxt.end(), 0);

            long long winSum = 0;                    
            for (int t = 1; t < k; t++) {
                winSum += dp[t - 1];
                if (winSum >= MOD) winSum -= MOD;

                int dropIdx = t - window - 1;
                if (dropIdx >= 0) {
                    winSum -= dp[dropIdx];
                    if (winSum < 0)  winSum += MOD;
                }
                nxt[t] = static_cast<int>(winSum);
            }
            dp.swap(nxt);
        }

        long long shortCnt = 0;
        for (int v : dp) {
            shortCnt += v;
            if (shortCnt >= MOD) shortCnt -= MOD;
        }

        long long ans = total - shortCnt;
        if (ans < 0) ans += MOD;
        return static_cast<int>(ans);
    }
};