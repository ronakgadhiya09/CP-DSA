class Solution {
public:
    string robotWithString(string s) {
        
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        stack<char> stk;
        string res;
        char minCharacter = 'a';

        for (char c : s) {
            stk.emplace(c);
            freq[c]--;
            while (minCharacter != 'z' && freq[minCharacter] == 0) {
                minCharacter++;
            }
            while (!stk.empty() && stk.top() <= minCharacter) {
                res.push_back(stk.top());
                stk.pop();
            }
        }

        return res;
    }
};