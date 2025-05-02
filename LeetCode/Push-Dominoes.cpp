class Solution {
public:
    string pushDominoes(string dominoes) {
        unordered_map<char, int> mp;
        mp['L'] = -1;
        mp['R'] = 1;

        int n = dominoes.size();
        vector<int> time(n, -1);
        vector<int> force(n, 0); 

        queue<pair<int, int>> q; 

        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'L' || dominoes[i] == 'R') {
                q.push({i, mp[dominoes[i]]});
                time[i] = 0;
                force[i] = mp[dominoes[i]];
            }
        }

        while (!q.empty()) {
            auto [i, dir] = q.front();
            q.pop();

            int ni = i + dir;
            if (ni < 0 || ni >= n || dominoes[ni] != '.') continue;

            if (time[ni] == -1) {
                time[ni] = time[i] + 1;
                force[ni] = dir;
                q.push({ni, dir});
            }
            else if (time[ni] == time[i] + 1 && force[ni] != dir) {
                force[ni] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            if (dominoes[i] == '.') {
                if (force[i] == -1) dominoes[i] = 'L';
                else if (force[i] == 1) dominoes[i] = 'R';
                else dominoes[i] = '.';
            }
        }

        return dominoes;
    }
};
