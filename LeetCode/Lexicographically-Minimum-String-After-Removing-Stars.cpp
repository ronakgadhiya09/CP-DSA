class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> min_heap;
        int n = s.size();
        vector<bool> is_deleted(n,false);

        for(int i = 0 ; i < n ;i++){
            if(s[i]=='*'){
                auto [c,negInd] = min_heap.top();
                min_heap.pop();
                int index = -1*negInd;

                is_deleted[index] = true;
                is_deleted[i] = true;
            }
            else min_heap.push({s[i],-1*i});
        }

        string ans = "";
        for(int i = 0 ; i < n; i++){
            if(!is_deleted[i]) ans.push_back(s[i]);
        }
        
        return ans;
    }
};