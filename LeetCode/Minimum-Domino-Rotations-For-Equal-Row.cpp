class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int topRot = 0, bottomRot = 0, n = tops.size();
        for (int i = 0; i < n; i++) {
            if (tops[i] != target && bottoms[i] != target)
                return INT_MAX;
            else if (tops[i] != target)
                topRot++;
            else if (bottoms[i] != target)
                bottomRot++;
        }
        return min(topRot, bottomRot);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops[0], tops, bottoms);
        if (tops[0] != bottoms[0])
            result = min(result, check(bottoms[0], tops, bottoms));
        return result == INT_MAX ? -1 : result;
    }
};
