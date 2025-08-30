class Solution {
private:
    template<typename KeyType, typename MapType>
    bool checkinMap(const KeyType& key, const MapType& mp) {
        return mp.find(key) != mp.end();
    }

    bool solve(int row, int column, vector<vector<char>>& board,
               unordered_map<int, unordered_set<char>>& rowMap,
               unordered_map<int, unordered_set<char>>& columnMap,
               unordered_map<int, unordered_set<char>>& subMap) {

        if (row == 9) return true;
        if (column == 9) return solve(row + 1, 0, board, rowMap, columnMap, subMap);

        if (board[row][column] != '.') {
            return solve(row, column + 1, board, rowMap, columnMap, subMap);
        }

        int subBoxIndex = (row / 3) * 3 + (column / 3);

        for (char i = '1'; i <= '9'; i++) {
            if (!checkinMap(i, rowMap[row]) && 
                !checkinMap(i, columnMap[column]) && 
                !checkinMap(i, subMap[subBoxIndex])) {

                board[row][column] = i;
                rowMap[row].insert(i);
                columnMap[column].insert(i);
                subMap[subBoxIndex].insert(i);

                if (solve(row, column + 1, board, rowMap, columnMap, subMap)) {
                    return true;
                }

                board[row][column] = '.';
                rowMap[row].erase(i);
                columnMap[column].erase(i);
                subMap[subBoxIndex].erase(i);
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rowMap;
        unordered_map<int, unordered_set<char>> columnMap;
        unordered_map<int, unordered_set<char>> subMap;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    rowMap[i].insert(board[i][j]);
                    columnMap[j].insert(board[i][j]);
                    int subBoxIndex = (i / 3) * 3 + (j / 3);
                    subMap[subBoxIndex].insert(board[i][j]);
                }
            }
        }

        solve(0, 0, board, rowMap, columnMap, subMap);
    }
};
