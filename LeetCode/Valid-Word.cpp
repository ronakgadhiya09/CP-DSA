class Solution {
public:
    bool isValid(string word) {

        if(word.size() < 3) return false;

        unordered_set<char> nums;
        unordered_set<char> cons;
        unordered_set<char> vows;

        char lower = 'a';
        char upper = 'A';
        vows.insert(lower);
        vows.insert(upper);
        for(int i = 0 ; i < 25; i++){
            lower++;
            upper++;
            if(lower == 'e' || lower == 'i' || lower == 'o' || lower  == 'u'){
                vows.insert(lower);
                vows.insert(upper);
            }
            else{
                cons.insert(lower);
                cons.insert(upper);
            }
        }
        
        for(char a = '0' ; a <= '9' ; a++) nums.insert(a);

        bool isVow = false;
        bool isCons = false;
        for(auto &c : word){
            if(!nums.count(c) && !vows.count(c) && !cons.count(c)) return false;
            else if(vows.count(c)) isVow = true;
            else if(cons.count(c)) isCons = true;
        }

        return isVow&isCons;
    }
};