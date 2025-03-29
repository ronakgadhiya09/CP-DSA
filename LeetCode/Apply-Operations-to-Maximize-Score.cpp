class Solution {
public:
    const long long MOD = 1e9 + 7;
    
    int primeScore(int x, vector<int>& spf) {
        int count = 0;
        int prev = -1;
        while (x > 1) {
            int p = spf[x];
            if (p != prev) {
                count++;
                prev = p;
            }
            x /= p;
        }
        return count;
    }
    
    vector<int> buildSPF(int maxVal) {
        vector<int> spf(maxVal + 1);
        for (int i = 1; i <= maxVal; i++) {
            spf[i] = i;
        }
        for (int i = 2; i * i <= maxVal; i++) {
            if (spf[i] == i) { 
                for (int j = i * i; j <= maxVal; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
        return spf;
    }
    
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while(exp > 0){
            if(exp & 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> spf = buildSPF(maxVal);
        
        vector<int> score(n);
        for (int i = 0; i < n; i++) {
            score[i] = primeScore(nums[i], spf);
        }
        
        vector<int> left(n), right(n);
        {
            stack<int> st;
            for (int i = 0; i < n; i++) {
                while (!st.empty() && score[st.top()] < score[i]) {
                    st.pop();
                }
                left[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
        }
        {
            while (!std::stack<int>().empty()) {} 
            stack<int> st;
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && score[st.top()] <= score[i]) {
                    st.pop();
                }
                right[i] = st.empty() ? n : st.top();
                st.push(i);
            }
        }
        
        vector<long long> cnt(n);
        for (int i = 0; i < n; i++) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;
            cnt[i] = leftCount * rightCount;
        }
        
        vector<pair<int, long long>> candidates;
        for (int i = 0; i < n; i++) {
            candidates.push_back({nums[i], cnt[i]});
        }
        
        sort(candidates.begin(), candidates.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });
        
        long long ans = 1;
        for (auto &p : candidates) {
            if (k == 0) break;
            long long times = min((long long)k, p.second);
            ans = (ans * modPow(p.first, times)) % MOD;
            k -= times;
        }
        return (int)ans;
    }
};
