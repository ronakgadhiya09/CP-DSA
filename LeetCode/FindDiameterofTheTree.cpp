class Solution {

    pair<int, int> dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        int farthestNode = node; 
        int maxDistance = 0; 

        for (auto& neighbour : adj[node]) {
            if (!visited[neighbour]) {
                auto [nextFarthest, distance] = dfs(neighbour, adj, visited); 
                if (distance + 1 > maxDistance) {
                    maxDistance = distance + 1;
                    farthestNode = nextFarthest;
                }
            }
        }
        return {farthestNode, maxDistance};
    }


    int dist(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        int max_dist = 0;
        for (auto& neighbour : adj[node]) {
            if (!visited[neighbour]) {
                max_dist = max(max_dist, 1 + dist(neighbour, adj, visited));
            }
        }
        return max_dist == 0 ? 1 : max_dist;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        int n = edges1.size()+1;
        int m = edges2.size()+1;

        vector<vector<int>> tree1(n), tree2(m);

        for (auto& edge : edges1) {
            int u = edge[0], v = edge[1];
            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }

        for (auto& edge : edges2) {
            int u = edge[0], v = edge[1];
            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }

        vector<bool> visited1(n, false), visited2(m, false);

        auto [leaf1,_] = dfs(0, tree1, visited1);
        fill(visited1.begin(), visited1.end(), false);
        int dia1 = dist(leaf1, tree1, visited1);
        fill(visited1.begin(), visited1.end(), false);

        auto [leaf2,_] = dfs(0, tree2, visited2);
        fill(visited2.begin(), visited2.end(), false);
        int dia2 = dist(leaf2, tree2, visited2);

        // cout << leaf1 << " " << leaf2 << endl;
        // cout << dia1 << " " << dia2 << endl;

        return max(dia1/2 + dia2/2 + 1,max(dia1-1,dia2-1));
    }
};
