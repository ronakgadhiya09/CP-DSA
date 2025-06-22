class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;  
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            ans.push_back(s.substr(i,k));
            i += k-1;
        }
        ans.back() += string(k - ans.back().length(), fill);
        return ans;
    }
};