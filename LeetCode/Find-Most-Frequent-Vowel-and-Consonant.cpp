class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        for(auto c : s) freq[c - 'a']++;

        int max_cons = 0;
        int max_vow = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(i == ('a' - 'a') || i == ('e' - 'a') || i == ('i' - 'a') || i == ('o' - 'a') || i == ('u' - 'a')){
                max_vow = max(max_vow,freq[i]);
            }
            else max_cons = max(max_cons,freq[i]);
        }
        
        return max_vow + max_cons;
    }
};