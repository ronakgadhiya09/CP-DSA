class Solution {
public:
    const long long MOD = 1e9 + 7;
    
    int getPrimeScore(int x, vector<int>& spf) {
        int count = 0;
        int prev = -1;
        while (x > 1) {
            int primeFactor = spf[x];
            if (primeFactor != prev) {  
                count++;
                prev = primeFactor;
            }
            x /= primeFactor;
        }
        return count;
    }
    
    vector<int> buildSmallestPrimeFactor(int maxVal) {
        vector<int> spf(maxVal + 1);
        for (int i = 1; i <= maxVal; i++) {
            spf[i] = i;
        }
        for (int i = 2; i * i <= maxVal; i++) {
            if (spf[i] == i) {  
                for (int j = i * i; j <= maxVal; j += i) {
                    if (spf[j] == j) {  
                        spf[j] = i;
                    }
                }
            }
        }
        return spf;
    }
    
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) {  
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> spf = buildSmallestPrimeFactor(maxVal);

        vector<int> primeScores(n);
        for (int i = 0; i < n; i++) {
            primeScores[i] = getPrimeScore(nums[i], spf);
        }
        
        vector<int> left(n), right(n);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && primeScores[st.top()] < primeScores[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && primeScores[st.top()] <= primeScores[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<long long> count(n);
        for (int i = 0; i < n; i++) {
            long long leftCount = i - left[i];  
            long long rightCount = right[i] - i;  
            count[i] = leftCount * rightCount;
        }

        vector<pair<int, long long>> candidates;
        for (int i = 0; i < n; i++) {
            candidates.push_back({nums[i], count[i]});
        }

        sort(candidates.begin(), candidates.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        long long result = 1;
        for (auto &p : candidates) {
            if (k == 0) break;
            long long times = min((long long)k, p.second);
            result = (result * modPow(p.first, times)) % MOD;
            k -= times;
        }

        return (int)result;
    }
};
