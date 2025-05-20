class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        vector<int> ps(n+2,0);

        for(auto &query : queries){
            int left = query[0];
            int right = query[1];

            if (left >= 0) ps[left]++;
            if (right + 1 < ps.size()) ps[right + 1]--;
        }

        for(int i = 1 ; i <= n; i++){
            ps[i] += ps[i-1];
        }

        for(int i = 0 ; i < n ;i++){
            if(nums[i] > ps[i]) return false;
        }
        
        return true;
    }
};