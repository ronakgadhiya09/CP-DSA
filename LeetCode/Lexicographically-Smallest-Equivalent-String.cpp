class Solution {
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &component) {
        visited[node] = true;
        component.push_back(node);
        for (auto &neigh : graph[node]) {
            if (!visited[neigh])
                dfs(neigh, graph, visited, component);
        }
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>> graph(26);
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> visited(26, false);
        vector<int> minPos(26);
        for (int i = 0; i < 26; i++) minPos[i] = i;

        for (int i = 0; i < 26; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, graph, visited, component);
                int mini = *min_element(component.begin(), component.end());
                for (int node : component) {
                    minPos[node] = mini;
                }
            }
        }

        string ans = "";
        for (char c : baseStr) {
            int ind = c - 'a';
            ans.push_back('a' + minPos[ind]);
        }
        return ans;
    }
};
