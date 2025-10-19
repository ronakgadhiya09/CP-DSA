class Solution {
private:
    void findNum(string &s,int a,int b,set<string> &seen){
        int n = s.size();
        string t = s;
        for(int i = 1; i <n; i+=2) t[i] = ((t[i] - '0' + a) % 10 ) + '0';
        if(!seen.count(t)){
            seen.insert(t);
            findNum(t,a,b,seen);
        }

        t = s.substr(n-b,b) + s.substr(0,n-b);
        if(!seen.count(t)){
            seen.insert(t);
            findNum(t,a,b,seen);
        }

        return;
    }

public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> seen;
        seen.insert(s);
        findNum(s,a,b,seen);
        return *seen.begin();
    }
};