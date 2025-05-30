class Solution {
private:
    void dfs(int node, vector<int> &edges, vector<bool> &visited, vector<int> &dist, int depth) {
        visited[node] = true;
        dist[node] = depth;

        if(edges[node] == -1 || visited[edges[node]]) return;
        dfs(edges[node], edges, visited, dist, depth + 1);
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, 1e9);
        vector<int> dist2(n, 1e9);

        vector<bool> visited(n, false);
        dfs(node1, edges, visited, dist1, 0);
        fill(visited.begin(), visited.end(), false);
        dfs(node2, edges, visited, dist2, 0);

        int minMaxDist = 1e9;
        int res = -1;

        for(int i = 0 ; i < n ; i++) {
            int maxDist = max(dist1[i], dist2[i]);
            if(maxDist < minMaxDist) {
                minMaxDist = maxDist;
                res = i;
            }
        }
        return res;
    }
};
