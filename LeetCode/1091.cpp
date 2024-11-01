class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int totalRows = grid.size();
        int totalColumns = grid[0].size();

        if(grid[0][0] == 1 || grid[totalRows-1][totalColumns-1] == 1) return -1;

        vector<vector<int>> dist(totalRows, vector<int>(totalColumns, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, 
            greater<tuple<int, int, int>>> pq;
        pq.push({1, 0, 0});
        dist[0][0] = 1;

        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while(!pq.empty()){
            
            auto [distance, x, y] = pq.top();
            pq.pop();

            if(x == totalRows - 1 && y == totalColumns - 1) return distance;

            for(int i = 0 ; i < 8 ; i++){

                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < totalRows && ny >= 0 && ny < totalColumns && 
                                grid[nx][ny] == 0 && dist[nx][ny] > distance + 1){
                    dist[nx][ny] = distance + 1;
                    pq.push({distance + 1, nx, ny});
                }
            }
        }

        return -1;
    }
};
