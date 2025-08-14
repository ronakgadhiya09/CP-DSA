class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto edge : redEdges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v,0});
        }

        for(auto edge : blueEdges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v,1});
        }

        vector<int> dist(n,INT_MAX);
        dist[0] = 0;

        vector<bool> visitedThroughRed(n,false);
        vector<bool> visitedThroughBlue(n,false);

        queue<pair<int,int>> bfs;
        bfs.push({0,0});
        bfs.push({0,1});

        int level = 0;
        while(!bfs.empty()){
            
            int m = bfs.size();

            for(int i = 0 ; i < m ; i++){
                auto [node,color] = bfs.front();
                bfs.pop();
                dist[node] = min(dist[node],level);
                if(color == 0) visitedThroughRed[node] = true;
                if(color == 1) visitedThroughBlue[node] = true;
                for(auto [neigh,ncol] : adj[node]){
                    if(ncol == 1 && color == 0 && !visitedThroughBlue[neigh]) bfs.push({neigh,ncol});
                    if(ncol == 0 && color == 1 && !visitedThroughRed[neigh]) bfs.push({neigh,ncol});
                }
            }

            level++;
        }

        for(int i = 0 ; i < n ; i++) if(dist[i]==INT_MAX) dist[i] = -1;
        return dist;
    }
};