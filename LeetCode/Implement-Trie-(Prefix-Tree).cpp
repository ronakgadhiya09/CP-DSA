struct TrieNode{
    TrieNode* children[26];
    bool isWordEnd;
};

struct TrieNode* getNode(void)
{
    struct TrieNode* pNode = new TrieNode;
    pNode->isWordEnd = false;
 
    for (int i = 0; i < 26; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}

class Trie {
    TrieNode* root;
    
public:
    Trie(){
        root = getNode();
    }
    
    void insert(string word) {

        TrieNode* pCrawl = root;

        for(auto &c: word){
            int index = c - 'a';
            if(!pCrawl->children[index]){
                TrieNode* temp = getNode();
                pCrawl->children[index] = temp;
            }
            pCrawl = pCrawl->children[index];
        }
        
        pCrawl->isWordEnd = true;
    }
    
    bool search(string word) {

        TrieNode* pCrawl = root;

        for(auto &c : word){
            int index  = c - 'a';
            if(!pCrawl->children[index]) return false;
            pCrawl = pCrawl->children[index];
        }
        
        return pCrawl->isWordEnd;
    }
    
    bool startsWith(string prefix) {

        TrieNode* pCrawl = root;

        for(auto &c : prefix){
            int index  = c - 'a';
            if(!pCrawl->children[index]) return false;
            pCrawl = pCrawl->children[index];
        }
        
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */