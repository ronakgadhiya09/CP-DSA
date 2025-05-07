typedef long long ll;
typedef pair<ll, pair<int, int>> State; 

class Solution {
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    bool inGrid(int x, int y, int n, int m) {
        return x>=0 && y>=0 && x<n && y<m;
    }

    ll dijkstra(const vector<vector<int>>& moveTime, vector<vector<ll>>& dist) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, {0,0}});
        
        while (!pq.empty()) {
            auto [t, p] = pq.top(); pq.pop();
            auto [x,y] = p;
            if (t > dist[x][y]) continue;
            if (x==n-1 && y==m-1) return t;

            for (auto& d: dir) {
                int nx = x + d.first, ny = y + d.second;
                if (!inGrid(nx,ny,n,m)) continue;
                
                ll depart = max(t, (ll)moveTime[nx][ny]);
                ll arrive = depart + 1;
                
                if (arrive < dist[nx][ny]) {
                    dist[nx][ny] = arrive;
                    pq.push({arrive, {nx, ny}});
                }
            }
        }
        return LLONG_MAX;
    }

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<ll>> dist(n, vector<ll>(m, LLONG_MAX));
        dist[0][0] = 0;
        return (int)dijkstra(moveTime, dist);
    }
};
