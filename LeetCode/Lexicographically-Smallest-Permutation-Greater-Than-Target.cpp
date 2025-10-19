class Solution {
public:
    bool dfs(int i, string &ans, const string &target, vector<int> &freq, bool greater) {
        int n = target.size();

        if (i == n) return greater; 

        if (greater) {
            for (int c = 0; c < 26; c++) {
                if (freq[c] > 0) {
                    freq[c]--; 
                    ans.push_back(c + 'a');
                    if (dfs(i + 1, ans, target, freq, true)) return true;
                    ans.pop_back();
                    freq[c]++;
                }
            }
            return false;
        }

        int t = target[i] - 'a';
        if (freq[t] > 0) {
            freq[t]--;
            ans.push_back(target[i]);
            if (dfs(i + 1, ans, target, freq, false)) return true;
            ans.pop_back();
            freq[t]++;
        }

        for (int c = t + 1; c < 26; c++) {
            if (freq[c] > 0) {
                freq[c]--;
                ans.push_back(c + 'a');
                if (dfs(i + 1, ans, target, freq, true)) return true;
                ans.pop_back();
                freq[c]++;
                break; 
            }
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26);
        for (char c : s) freq[c - 'a']++;

        string ans = "";
        if (dfs(0, ans, target, freq, false)) return ans; 
        return "";
    }
};
