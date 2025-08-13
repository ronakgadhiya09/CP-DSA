class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.empty() || s.empty()) return {};
        int m = words[0].size();
        int n = words.size();
        int k = s.size();
        if(k < m * n) return {};

        unordered_map<string,int> need;
        for(const string &w : words) need[w]++;

        vector<int> ans;
        // process m possible offsets
        for(int offset = 0; offset < m; ++offset){
            int left = offset;
            int count = 0; // number of words currently in window
            unordered_map<string,int> window;
            for(int right = offset; right + m <= k; right += m){
                string w = s.substr(right, m);
                if(need.count(w)){
                    window[w]++;
                    count++;
                    // if this word occurs too many times, move left forward
                    while(window[w] > need[w]){
                        string leftWord = s.substr(left, m);
                        window[leftWord]--;
                        left += m;
                        count--;
                    }
                    if(count == n) {
                        ans.push_back(left);
                        // move left one word to continue searching for next possible
                        string leftWord = s.substr(left, m);
                        window[leftWord]--;
                        left += m;
                        count--;
                    }
                } 
                else {
                    // invalid word — reset window
                    window.clear();
                    count = 0;
                    left = right + m;
                }
            }
        }
        return ans;
    }
};
