class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max_dif = -1;
        int n = nums.size();
        int suf_max = -1;
        for(int i = n - 1 ; i >= 0 ; i--){
            max_dif = max(max_dif, nums[i] < suf_max ? suf_max - nums[i] : -1);
            suf_max = max(suf_max,nums[i]);
        }
        return max_dif;
    }
};