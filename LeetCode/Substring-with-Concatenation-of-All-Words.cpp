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
        for(int offset = 0; offset < m; ++offset){
            int left = offset;
            int count = 0;
            unordered_map<string,int> window;
            for(int right = offset; right + m <= k; right += m){
                string w = s.substr(right, m);
                if(need.count(w)){
                    window[w]++;
                    count++;
                    while(window[w] > need[w]){
                        string leftWord = s.substr(left, m);
                        window[leftWord]--;
                        left += m;
                        count--;
                    }
                    if(count == n) {
                        ans.push_back(left);
                        string leftWord = s.substr(left, m);
                        window[leftWord]--;
                        left += m;
                        count--;
                    }
                } 
                else {
                    window.clear();
                    count = 0;
                    left = right + m;
                }
            }
        }
        return ans;
    }
};
