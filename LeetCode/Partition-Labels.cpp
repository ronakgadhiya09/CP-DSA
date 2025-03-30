class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> charFreq(26,0);

        for(auto &c : s){
            charFreq[ c - 'a']++;
        }

        unordered_set<char> charInSubStr;

        int n = s.size();
        int left = 0;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){

            char c = s[i];
            charInSubStr.insert(c);
            charFreq[c - 'a']--;

            bool flag = true;
            for(auto &ch : charInSubStr){
                if(charFreq[ch - 'a']){
                    flag = false;
                    break;
                }
            }

            if(flag){
                ans.push_back(i - left + 1);
                left = i + 1;
                charInSubStr.clear();
            }
        }
        
        return ans;
    }
};