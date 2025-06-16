class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max_dif = -1;
        int n = nums.size();
        vector<int> suf_max(n+1,-1);
        for(int i = n - 1 ; i >= 0 ; i--){
            suf_max[i] = max(suf_max[i+1],nums[i]);
        }
        for(int i = 0 ; i < n ;i++) max_dif = max(max_dif,suf_max[i] > nums[i] ? suf_max[i] - nums[i] : -1);
        return max_dif;
    }
};