class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s;
        
        while (true) {
            int total = a + b + c;

            if (total == 0) break;

            if (a >= b && a >= c) {
                if (s.size() >= 2 && s[s.size() - 1] == 'a' && s[s.size() - 2] == 'a') {
                    if (b >= c && b > 0) {
                        s += 'b';
                        b--;
                    } else if (c > 0) {
                        s += 'c';
                        c--;
                    } else {
                        break;
                    }
                } 
                else {
                    s += 'a';
                    a--;
                }
            }
            else if (b >= a && b >= c) {
                if (s.size() >= 2 && s[s.size() - 1] == 'b' && s[s.size() - 2] == 'b') {
                    if (a >= c && a > 0) {
                        s += 'a';
                        a--;
                    } else if (c > 0) {
                        s += 'c';
                        c--;
                    } else {
                        break; 
                    }
                } 
                else {
                    s += 'b';
                    b--;
                }
            }
            else if (c >= a && c >= b) {
                if (s.size() >= 2 && s[s.size() - 1] == 'c' && s[s.size() - 2] == 'c') {
                    if (a >= b && a > 0) {
                        s += 'a';
                        a--;
                    } else if (b > 0) {
                        s += 'b';
                        b--;
                    } else {
                        break;
                    }
                }
                 else {
                    s += 'c';  
                    c--;
                }
            }
        }

        return s;
    }
};
