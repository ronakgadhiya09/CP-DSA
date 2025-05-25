class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> freq;
        for(auto& word : words) freq[word]++;
        
        int ans = 0;
        bool has_middle = false;
        
        for(auto& [word, count] : freq){
            string rev = string(word.rbegin(), word.rend());
            
            if(word != rev){
                if(freq.count(rev)){
                    int pair_count = min(count, freq[rev]);
                    ans += pair_count * 4;
                    freq[word] -= pair_count;
                    freq[rev] -= pair_count;
                }
            }
            else{
                int pair_count = count / 2;
                ans += pair_count * 4;
                if(count % 2 == 1) has_middle = true;
            }
        }
        
        if(has_middle) ans += 2;
        
        return ans;
    }
};
