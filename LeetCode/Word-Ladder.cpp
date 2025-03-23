class Solution {

private:
    bool checkAdj(const string &a,const string &b){
        int n = a.size();
        int difIndexCount = 0;
        for(int i = 0 ; i < n ; i++){
            if(a[i]!=b[i]) difIndexCount++;
            if(difIndexCount > 1) return false;
        }
        return true;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(beginWord==endWord) return 0;
        unordered_map<string,vector<string>> adj;

        int n = wordList.size();
        for(int i = 0 ; i < n ; i++){
            string curWord = wordList[i];
            if(checkAdj(beginWord,curWord)){
                adj[curWord].push_back(beginWord);
                adj[beginWord].push_back(curWord);
            }
            for(int j = i + 1 ; j < n ; j++){
                string nextWord = wordList[j];
                if(checkAdj(curWord,nextWord)){
                    adj[curWord].push_back(nextWord);
                    adj[nextWord].push_back(curWord);
                }
            }
        }

        unordered_set<string> visited;
        queue<string> bfsq;
        bfsq.push(beginWord);
        visited.insert(beginWord);

        int transformations = 1;
        while(!bfsq.empty()){

            int m = bfsq.size();

            for(int i = 0 ; i < m ; i++){
                string curWord = bfsq.front();
                bfsq.pop();

                if(curWord == endWord) return transformations;

                visited.insert(curWord);
                for(auto &newWord : adj[curWord]){
                    if(visited.find(newWord)==visited.end()){
                        bfsq.push(newWord);
                    }
                }
            }

            transformations++;
        }

        return 0;
    }
};