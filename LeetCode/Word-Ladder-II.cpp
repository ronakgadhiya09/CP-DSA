class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, 
                                                    vector<string>& wordList) {
                                                        
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        unordered_map<string, vector<string>> parents;
        unordered_set<string> current_level{beginWord};
        bool found = false;

        while (!current_level.empty() && !found) {
            unordered_set<string> next_level;
            for (const string& word : current_level)
                dict.erase(word);

            for (const string& word : current_level) {
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if (!dict.count(temp)) continue;

                        next_level.insert(temp);
                        parents[temp].push_back(word);

                        if (temp == endWord) found = true;
                    }
                    temp[i] = original;
                }
            }
            swap(current_level, next_level);
        }

        vector<vector<string>> res;
        if (found) {
            vector<string> path = {endWord};
            backtrack(endWord, beginWord, parents, path, res);
        }
        return res;
    }

    void backtrack(string word, const string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path, vector<vector<string>>& res) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        for (const string& p : parents[word]) {
            path.push_back(p);
            backtrack(p, beginWord, parents, path, res);
            path.pop_back();
        }
    }
};
