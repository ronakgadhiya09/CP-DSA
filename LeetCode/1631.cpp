class Solution {
private:
    struct state {
        int effort;
        int x;
        int y;

        state(int e, int x, int y) : effort(e), x(x), y(y) {}
    };

    struct comp {
        bool operator()(const state& a, const state& b) const {
            return a.effort > b.effort;
        }
    };

    int dx[8] = {-1, 0, 0, 1};
    int dy[8] = {0, -1, 1, 0};

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();
        vector<vector<int>> minEffort(rows, vector<int>(columns, 1e9));
        priority_queue<state, vector<state>, comp> pq;

        pq.push(state(0, 0, 0));

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int curEf = top.effort;
            int curX = top.x;
            int curY = top.y;

            if (curX == rows - 1 && curY == columns - 1) return curEf;

            for (int i = 0; i < 8; i++) {
                int nX = curX + dx[i];
                int nY = curY + dy[i];

                if (nX < rows && nX >= 0 && nY < columns && nY >= 0) {
                    int newEffort = max(curEf, abs(heights[curX][curY] - heights[nX][nY]));
                    if (minEffort[nX][nY] > newEffort) {
                        minEffort[nX][nY] = newEffort;
                        pq.push(state(newEffort, nX, nY));
                    }
                }
            }
        }

        return 0;
    }
};
