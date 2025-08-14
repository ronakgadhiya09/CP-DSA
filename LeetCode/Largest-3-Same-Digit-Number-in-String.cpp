class Solution {
public:
    string largestGoodInteger(string num) {
        vector<vector<int>> positions(10);
        int n = num.length();
        for(int i = 0 ; i < n; i++) positions[num[i] - '0'].push_back(i);

        for(int i = 9; i >= 0; i--){
            int m = positions[i].size();
            for(int j = 0 ; j < m - 2 ; j++){
                if(positions[i][j] + 1 == positions[i][j+1] && positions[i][j+1] + 1 == positions[i][j+2]){
                    string s = to_string(i);
                    char c = s.back();
                    s.push_back(c);
                    s.push_back(c);
                    return s;
                }
            }
        }

        return "";
    }
};