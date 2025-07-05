class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n+1,0);
        int ans = -1;
        for(auto &num : arr) if(num <= n) freq[num]++;
        for(int i = 1 ; i <= n ; i++) if(freq[i] == i) ans = i;
        return ans;
    }
};