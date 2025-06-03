class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, 
                   vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, 
                   vector<int>& initialBoxes) {

        int n = status.size();
        vector<bool> visited(n, false), hasBox(n, false);
        queue<int> q;

        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box]) q.push(box);
        }

        int total = 0;

        while (!q.empty()) {
            int box = q.front(); q.pop();
            if (visited[box]) continue;
            visited[box] = true;
            total += candies[box];

            for (int k : keys[box]) {
                if (!status[k]) {
                    status[k] = 1;
                    if (hasBox[k] && !visited[k]) {
                        q.push(k);
                    }
                }
            }

            for (int b : containedBoxes[box]) {
                hasBox[b] = true;
                if (status[b] && !visited[b]) {
                    q.push(b);
                }
            }
        }

        return total;
    }
};
