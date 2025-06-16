class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max_dif = -1;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ;j++){
                if(nums[j] > nums[i])
                    max_dif = max(max_dif,nums[j] - nums[i]);
            }
        }
        return max_dif;
    }
};