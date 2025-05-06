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

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = getNode();
    }
    
    void addWord(string word) {
        TrieNode* pCrawl = root;
        for (char c : word) {
            int index = c - 'a';
            if (!pCrawl->children[index]) {
                pCrawl->children[index] = getNode();
            }
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isWordEnd = true;
    }

    bool searchInTrie(TrieNode* root, string s) {
        TrieNode* cur = root;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '.') {
                for (int j = 0; j < 26; j++) {
                    if (cur->children[j] && searchInTrie(cur->children[j], s.substr(i + 1)))
                        return true;
                }
                return false;
            } else {
                int index = c - 'a';
                if (!cur->children[index]) return false;
                cur = cur->children[index];
            }
        }
        return cur && cur->isWordEnd;
    }

    bool search(string word) {
        return searchInTrie(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */