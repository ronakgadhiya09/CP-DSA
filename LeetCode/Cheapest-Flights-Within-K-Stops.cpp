class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            adj[from].push_back({to, price});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // {cost, node, stops}
        pq.push({0, src, 0});

        vector<int> stopsArr(n, INT_MAX);
        while (!pq.empty()) {
            auto top = pq.top();
            int costToNode = top[0];
            int node = top[1];
            int stops = top[2];
            pq.pop();

            if (node == dst) return costToNode;
            if (stops > k || stops >= stopsArr[node]) continue;

            stopsArr[node] = stops;

            for (auto &[neighbour, price] : adj[node]) {
                pq.push({costToNode + price, neighbour, stops + 1});
            }
        }

        return -1;
    }
};
