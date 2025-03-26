class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vals;
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                vals.push_back(grid[i][j]);
            }
        }

        int base = vals[0];
        for (int v : vals) {
            if (abs(v - base) % x != 0) return -1;
        }

        for (int &v : vals) {
            v = (v - base) / x;
        }

        sort(vals.begin(), vals.end());
        int median = vals[vals.size() / 2];

        int ops = 0;
        for (int v : vals) {
            ops += abs(v - median);
        }

        return ops;
    }
};
