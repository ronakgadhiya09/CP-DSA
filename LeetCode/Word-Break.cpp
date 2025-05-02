struct TrieNode {
    TrieNode* children[26];
    bool isWordEnd;
};

TrieNode* getNode() {
    TrieNode* pNode = new TrieNode;
    pNode->isWordEnd = false;
    for (int i = 0; i < 26; i++) pNode->children[i] = nullptr;
    return pNode;
}

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = getNode();
    }

    TrieNode* getroot() {
        return root;
    }

    void insert(const string& s) {
        TrieNode* pCrawl = root;
        for (char c : s) {
            int index = c - 'a';
            if (!pCrawl->children[index]) {
                pCrawl->children[index] = getNode();
            }
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isWordEnd = true;
    }

    bool find(const string& s) {
        TrieNode* cur = root;
        for (char c : s) {
            int index = c - 'a';
            if (!cur->children[index]) return false;
            cur = cur->children[index];
        }
        return cur->isWordEnd;
    }
};

class Solution {
    unordered_map<string,bool> dp;
private:
    bool ispossible(Trie& T, const string& s) {
        if(dp.count(s)) return dp[s];
        if (T.find(s)) return dp[s] = true;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (T.find(left) && ispossible(T, right)) return dp[s] = true;
        }
        return dp[s] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie T;
        for (auto& word : wordDict) T.insert(word);
        return ispossible(T, s);
    }
};
