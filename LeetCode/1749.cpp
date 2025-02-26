class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = abs(nums[0]);
        int posSum = 0;
        int negSum = 0;
        for(int r = 0 ; r < n ; r++){
            posSum += nums[r];
            negSum += nums[r];
            if(posSum < 0){
                posSum = 0;
            }
            if(negSum > 0){
                negSum = 0;
            }
            maxi = max(maxi,max(posSum,-negSum));
        }
        return maxi;
    }
};
