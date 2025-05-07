typedef long long ll;
#include <tuple>
using State = std::tuple<ll,ll,int,int>;  

class Solution {
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    bool inGrid(int x, int y, int n, int m) {
        return x>=0 && y>=0 && x<n && y<m;
    }

    ll h(int x, int y, int n, int m) {
        return (ll)( (n-1 - x) + (m-1 - y) );
    }

    ll astar(const vector<vector<int>>& moveTime, vector<vector<ll>>& dist) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<State, vector<State>, greater<State>> pq;
        dist[0][0] = 0;
        pq.emplace(h(0,0,n,m), 0, 0, 0);

        while(!pq.empty()) {
            auto [f, g, x, y] = pq.top(); pq.pop();
            if (g > dist[x][y]) continue;
            if (x==n-1 && y==m-1) return g;

            for (auto& d : dir) {
                int nx = x + d.first, ny = y + d.second;
                if (!inGrid(nx,ny,n,m)) continue;

                ll depart = max(g, (ll)moveTime[nx][ny]);
                ll ng = depart + 1;
                if (ng < dist[nx][ny]) {
                    dist[nx][ny] = ng;
                    ll nf = ng + h(nx,ny,n,m);
                    pq.emplace(nf, ng, nx, ny);
                }
            }
        }
        return LLONG_MAX;
    }

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<ll>> dist(n, vector<ll>(m, LLONG_MAX));
        return (int)astar(moveTime, dist);
    }
};
