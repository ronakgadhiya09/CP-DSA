class DSU {
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) {
        parent.resize(n+1);
        for (int i = 1; i <= n; i++) 
            parent[i] = i;
        rank.resize(n+1, 0);
    }
    
    int findfinalparent(int u) {
        if(parent[u] == u)
            return u;
        return parent[u] = findfinalparent(parent[u]);
    }
    
    void unite(int u, int v) {
        int u_parent = findfinalparent(u);
        int v_parent = findfinalparent(v);
        if(u_parent == v_parent) return;
        if(rank[u_parent] > rank[v_parent])
            parent[v_parent] = u_parent;
        else if(rank[u_parent] < rank[v_parent])
            parent[u_parent] = v_parent;
        else{
            parent[v_parent] = u_parent;
            rank[u_parent]++;
        }
    }
    
    bool isConnected(int u, int v) {
        return findfinalparent(u) == findfinalparent(v);
    }
};

class Solution {
public:
    void dfs(int node, vector<vector<bool>> &visitedEdge, vector<vector<vector<int>>> &adj, int &weight) {
        for (int i = 0; i < adj[node].size(); i++) {
            if (!visitedEdge[node][i]) {
                visitedEdge[node][i] = true;
                int v = adj[node][i][0];
                int w = adj[node][i][1];
                weight &= w;
                for (int j = 0; j < adj[v].size(); j++) {
                    if (adj[v][j][0] == node && !visitedEdge[v][j]) {
                        visitedEdge[v][j] = true;
                        break;  
                    }
                }
                dfs(v, visitedEdge, adj, weight);
            }
        }
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        auto ds = new DSU(n);
        vector<vector<vector<int>>> adj(n);
        unordered_map<int,int> minW;
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            ds->unite(u, v);
        }
        
        vector<vector<bool>> visitedEdge(n);
        for (int i = 0; i < n; i++) {
            visitedEdge[i].resize(adj[i].size(), false);
        }
    
        for (int i = 0; i < n; i++){
            if (ds->findfinalparent(i) == i) {
                int x = INT_MAX;
                dfs(i, visitedEdge, adj, x);
                minW[i] = x;
            }
        }
        
        vector<int> ans;
        for(auto &q : query){
            int u = q[0];
            int v = q[1];
            
            int uPar = ds->findfinalparent(u);
            int vPar = ds->findfinalparent(v);
            
            if(uPar == vPar){
                ans.push_back(minW[uPar]);
            }
            else{
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};
