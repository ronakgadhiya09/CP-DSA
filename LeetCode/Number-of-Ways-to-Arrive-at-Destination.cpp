const int M = 1e9 + 7;
#define ll long long
#define pll pair<ll, ll>

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, vector<pair<ll,ll>>> adj;
        
        for(auto& road: roads) {
            adj[road[0]].push_back({(ll)road[1], (ll)road[2]});
            adj[road[1]].push_back({(ll)road[0], (ll)road[2]});
        }
        
        vector<pll> dp(n, {1e15, 0});
        dp[0] = {0, 1};
        
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, 0});
        
        while(pq.size()) {
            auto curr = pq.top(); pq.pop();
            ll cost = curr.first;
            ll node = curr.second;
            
            for(auto& child: adj[node]) {
                ll next = child.first;
                ll wt = child.second;
                
                if(dp[next].first > wt + cost) {
                    dp[next] = {wt+cost, dp[node].second};
                    pq.push({ dp[next].first, next });
                }
                
                else if(dp[next].first == wt + cost) {
                    dp[next].second += dp[node].second;
                    dp[next].second %= M;
                }
            }
        }
        return (dp[n-1].second);
    }
};