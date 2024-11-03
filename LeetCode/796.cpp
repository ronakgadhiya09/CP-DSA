class Solution {
public:
    bool rotateString(string s, string goal) {

        int n = s.size();
        int m = goal.size();

        if(n!=m) return false;
        bool flag = false;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                flag = false;
                for(int k = 0 ; k < n ;k++){
                    if(s[(i+k)%n]!=goal[(j+k)%n]){
                        flag = true;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(!flag) break;
        }
        
        return !flag;
    }
};
