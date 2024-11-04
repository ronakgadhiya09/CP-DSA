class Solution {
public:
    string compressedString(string word) {

        int n = word.size();
        string ans;
        for(int i = 0 ; i < n ;){

            int count = 0;
            int j = i;
            while(count < 9 && j < n && word[i]==word[j]){
                count++;
                j++;
            }
            ans.push_back(count + '0');
            ans.push_back(word[i]);
            i = j;
        }
        
        return ans;
    }
};
