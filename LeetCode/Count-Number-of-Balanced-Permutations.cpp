static const int MOD = 1000000007;
typedef long long ll;

ll modpow(ll a, ll e = MOD-2) {
    ll res = 1;
    while (e > 0) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

vector<ll> fact, invfact;

void init_factorials(int n) {
    fact.resize(n+1);
    invfact.resize(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
    invfact[n] = modpow(fact[n]);
    for (int i = n; i > 0; i--) invfact[i-1] = invfact[i] * i % MOD;
}

ll comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

class Solution {
public:
    int countBalancedPermutations(string num) {
        int n = num.size();
        vector<int> freq(10, 0);
        for (char c : num) freq[c - '0']++;

        string velunexorai = num;

        int totalSum = 0;
        for (int d = 0; d < 10; d++) totalSum += d * freq[d];
        if (totalSum % 2 != 0) return 0;
        int target = totalSum / 2;

        int oddCount = n / 2;
        int evenCount = n - oddCount;

        init_factorials(n);

        vector<vector<ll>> dp(oddCount + 1, vector<ll>(target + 1, 0));
        dp[0][0] = 1;

        for (int d = 0; d < 10; d++) {
            int f = freq[d];
            if (f == 0) continue;
            vector<vector<ll>> ndp(oddCount + 1, vector<ll>(target + 1, 0));
            for (int c = 0; c <= oddCount; c++) {
                for (int s = 0; s <= target; s++) {
                    ll ways = dp[c][s];
                    if (!ways) continue;
                    for (int k = 0; k <= f && c + k <= oddCount && s + d * k <= target; k++) {
                        ll weight = invfact[k] * invfact[f - k] % MOD;
                        ndp[c + k][s + d * k] = (ndp[c + k][s + d * k] + ways * weight) % MOD;
                    }
                }
            }
            dp.swap(ndp);
        }

        ll res = dp[oddCount][target];
        res = res * fact[oddCount] % MOD;
        res = res * fact[evenCount] % MOD;
        return (int)res;
    }
};