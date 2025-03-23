class Solution {

private:
    bool check(string& s, string& t) {
        if (s.length() != t.length())
            return false;

        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i])
                count++;
        }

        return (count == 1);
    }

    bool findstring(vector<string>& words, string& word) {

        for (auto s : words) {
            if (s == word)
                return true;
        }

        return false;
    }

public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        if (!findstring(wordList, endWord))
            return 0;

        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        while (!q.empty()) {

            int n = q.size();

            for (int i = 0; i < n; i++) {

                auto [word,dist] = q.front();
                q.pop();

                if (word == endWord)
                    return dist;

                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        word[i] = ch;

                        if(st.find(word)!=st.end()){
                            st.erase(word);
                            q.push({word,dist+1});
                        }
                    }
                    word[i] = original;
                }
            }
        }

        return 0;
    }
};