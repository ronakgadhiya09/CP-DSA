class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> grid(n * n + 1, -1);
        int idx = 1;
        bool right = true;

        for(int i = n - 1; i >= 0; i--) {
            if(right) {
                for(int j = 0; j < n; j++) grid[idx++] = board[i][j];
            } else {
                for(int j = n - 1; j >= 0; j--) grid[idx++] = board[i][j];
            }
            right = !right;
        }

        queue<int> q;
        vector<int> visited(n * n + 1, 0);
        q.push(1);
        visited[1] = 1;
        int moves = 0;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int curr = q.front(); q.pop();
                if(curr == n * n) return moves;

                for(int dice = 1; dice <= 6 && curr + dice <= n * n; dice++) {
                    int next = curr + dice;
                    if(grid[next] != -1) next = grid[next];
                    if(!visited[next]) {
                        visited[next] = 1;
                        q.push(next);
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};