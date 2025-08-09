class Solution {
private:
    unordered_map<int, unordered_map<int, double>> dp;

    double calcProb(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5; // both empty same time
        if (a <= 0) return 1.0;           // A empty first
        if (b <= 0) return 0.0;           // B empty first

        if (dp[a][b]) return dp[a][b];

        double res = 0.25 * (
            calcProb(a - 4, b) +
            calcProb(a - 3, b - 1) +
            calcProb(a - 2, b - 2) +
            calcProb(a - 1, b - 3)
        );

        return dp[a][b] = res;
    }

public:
    double soupServings(int n) {
        if (n >= 4800) return 1.0; 
        int m = (n + 24) / 25;
        return calcProb(m, m);
    }
};
