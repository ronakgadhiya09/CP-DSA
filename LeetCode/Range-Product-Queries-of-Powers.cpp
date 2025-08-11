class Solution {
private:
    const int MOD = 1e9 + 7;

    int binExp(int a, int b) {
        int result = 1;
        a %= MOD; 

        while (b) {
            if (b & 1) 
                result = (1LL * result * a) % MOD; 
            a = (1LL * a * a) % MOD;
            b >>= 1;
        }

        return result;
    }

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for(int i = 0; i < 32; i++) if(1<<i & n) powers.push_back(i);
        int m = powers.size();
        vector<int> prefix(m+1);
        for(int i = 0; i < m; i++) prefix[i+1] = powers[i] + prefix[i];

        vector<int> ans;
        for(auto &query : queries){
            int left = query[0];
            int right = query[1];
            int pow = prefix[right+1] - prefix[left];
            ans.push_back(binExp(2,pow));
        }

        return ans;
    }
};