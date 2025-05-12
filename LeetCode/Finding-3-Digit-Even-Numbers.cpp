class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        int n = digits.size();
        for(int i = 0 ;i < n ;i++) freq[digits[i]]++;
        vector<int> ans;

        for(int a = 1 ; a <= 9 ;a++){
            for(int b = 0 ; b <= 9 ;b++){
                for(int c = 0 ; c <= 9 ;c++){
                    int number = 100*a + 10*b + c;
                    freq[a]--;
                    freq[b]--;
                    freq[c]--;
                    if(freq[a] >= 0 && freq[b] >= 0 && freq[c] >= 0 && number%2==0) 
                                                                    ans.push_back(number);
                    freq[a]++;
                    freq[b]++;
                    freq[c]++;
                }
            }
        }
        
        return ans;
    }
};
