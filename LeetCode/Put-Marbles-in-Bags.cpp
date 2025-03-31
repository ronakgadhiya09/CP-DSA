class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;
        
        int m = n - 1;
        vector<long long> diffs(m);
        for (int i = 0; i < m; i++) {
            diffs[i] = (long long)weights[i] + weights[i+1];
        }
        
        sort(diffs.begin(), diffs.end());
        
        long long maxSum = 0, minSum = 0;
        for (int i = 0; i < k - 1; i++) {
            maxSum += diffs[m - 1 - i];
            minSum += diffs[i];
        }
        
        return maxSum - minSum;
    }
};
