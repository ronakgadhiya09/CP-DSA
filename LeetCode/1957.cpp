class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if(n<=2) return s;
        string ans = "";
        for(int l = 0; l < n ;){
            int r = l+1;
            while(r<n && s[l]==s[r]) r++;
            int rep = r - l + 1;
            if(rep>2){
                ans.push_back(s[l]);
            }
            ans.push_back(s[l]);
            l = r;
        }
        return ans;
    }
};
