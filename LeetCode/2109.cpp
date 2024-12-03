class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

        string ans = "";
        int m = spaces.size();
        int l = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(l < m && i==spaces[l]){
                ans.push_back(' ');
                l++;
                // continue;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
