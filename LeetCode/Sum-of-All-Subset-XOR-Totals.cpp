class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(auto &num : nums) ans |= num;
        return ans << n-1;
    }
};