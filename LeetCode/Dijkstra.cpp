class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v,w});
            // adj[v].push_back({u,w});
        }
        
        vector<int> dist(V,1e9);
        dist[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<bool> visited(V,false);
        
        while(!pq.empty()){
            
            auto node = pq.top().second;
            pq.pop();
            visited[node] = true;
            
            for(auto &p : adj[node]){
                auto neigh = p.first;
                auto cost = p.second;
                if(dist[node] + cost < dist[neigh]){
                    dist[neigh] = dist[node] + cost;
                }
                
                if(!visited[neigh]){
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        
        for(int i = 0 ; i < V ;i++){
            if(dist[i]==1e9) dist[i] = -1;
        }
        
        return dist;
    }
};
