class Solution {
private:
    string rle(string s){
        string ans;
        int n = s.size();
        for(int i = 0; i < n ;i++){
            int numbers = 0;
            int cur = i;
            while(s[i]==s[cur]){
                numbers++;
                i++;
            }
            i--;
            string freq = to_string(numbers);
            for(auto &c : freq) ans.push_back(c);
            ans.push_back(s[i]);
        }
        return ans;
    }

public:
    string countAndSay(int n) {
        if(n==1) return "1";
        return rle(countAndSay(n-1));
    }
};