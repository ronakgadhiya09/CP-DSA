class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (m > n) return 0;

        vector<int> need(26, 0), have(26, 0);
        for (char c : word2) need[c - 'a']++;

        int total_types = 0;
        for (int i = 0; i < 26; i++) if (need[i] > 0) total_types++;

        long long ans = 0;
        int satisfied = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            int r = word1[right] - 'a';
            have[r]++;
            if (need[r] > 0 && have[r] == need[r]) satisfied++;

            // While current window [left..right] satisfies all required counts,
            // every extension to the right (right..n-1) is valid for this left,
            // so add (n - right). Then shrink from left and continue.
            while (satisfied == total_types && left <= right) {
                ans += (n - right);

                int l = word1[left] - 'a';
                // If removing this char will break a previously satisfied requirement,
                // update satisfied BEFORE decrementing have[l].
                if (need[l] > 0 && have[l] == need[l]) satisfied--;
                have[l]--;
                left++;
            }
        }

        return ans;
    }
};
