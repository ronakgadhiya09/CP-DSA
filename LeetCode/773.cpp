class Solution {
private:
    vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 0}};

    int h(vector<vector<int>>& board) {
        int ans = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 0) {
                    int targetX = (board[i][j] - 1) / 3;
                    int targetY = (board[i][j] - 1) % 3;
                    ans += abs(i - targetX) + abs(j - targetY);
                }
            }
        }
        return ans;
    }

    pair<int, int> findzero(vector<vector<int>>& board) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (!board[i][j]) return {i, j};
            }
        }
        return {0, 0};
    }

    int a_star(vector<vector<int>>& board) {
        
        priority_queue<pair<int, pair<int, vector<vector<int>>>>, 
            vector<pair<int, pair<int, vector<vector<int>>>>>, greater<>> pq;
        map<vector<vector<int>>, bool> visited;

        int initial_heuristic = h(board);
        pq.push({initial_heuristic, {0, board}});

        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        
        while (!pq.empty()) {
            auto [priority, state] = pq.top();
            auto [real_cost, cur_board] = state;
            pq.pop();

            if (cur_board == goal) return real_cost;

            if (visited[cur_board]) continue;
            visited[cur_board] = true;

            auto [x, y] = findzero(cur_board);

            for (auto& it : dir) {
                int nx = x + it[0];
                int ny = y + it[1];

                if (nx >= 0 && nx < 2 && ny >= 0 && ny < 3) {
                    swap(cur_board[nx][ny], cur_board[x][y]);
                    if (!visited[cur_board]) {
                        int new_cost = real_cost + 1; 
                        pq.push({new_cost + h(cur_board), {new_cost, cur_board}});
                    }
                    swap(cur_board[nx][ny], cur_board[x][y]);
                }
            }
        }

        return -1; 
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        return a_star(board);
    }
};
