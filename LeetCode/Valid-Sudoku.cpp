class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> boxes(9, vector<bool>(9, false));
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char num = board[r][c];
                if (num == '.') continue;

                int val = num - '1';
                int boxIndex = (r / 3) * 3 + c / 3;

                if (rows[r][val] || cols[c][val] || boxes[boxIndex][val]) {
                    return false;
                }

                rows[r][val] = true;
                cols[c][val] = true;
                boxes[boxIndex][val] = true;
            }
        }
        return true;
    }
};
