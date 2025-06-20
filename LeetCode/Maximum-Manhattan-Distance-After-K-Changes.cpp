class Solution {
public:
    int maxDistance(string s, int k) {
        int h = 0, v=0;
        int n = s.size();
        int ans = 1;
        for(int i = 0 ; i < n ; i++){
            char c = s[i];
            if(c == 'N') v++;
            else if(c == 'S') v--;
            else if(c == 'E') h++;
            else h--;
            ans = max(min(abs(h)+abs(v)+2*k,i+1),ans);
        }
        return ans;
    }
};