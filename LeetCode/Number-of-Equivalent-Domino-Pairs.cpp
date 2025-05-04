class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> count;
        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            count[{min(a, b), max(a, b)}]++;
        }

        int equipairs = 0;
        for (auto& [_, freq] : count) {
            equipairs += freq * (freq - 1) / 2;
        }

        return equipairs;
    }
};
