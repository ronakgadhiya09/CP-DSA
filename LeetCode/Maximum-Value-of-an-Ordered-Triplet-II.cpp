class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n = nums.size();
        vector<int> sufMax(n);

        sufMax[n-1] = 0;
        for(int i = n-2 ; i >= 0 ; i--){
            sufMax[i] = max(sufMax[i+1],nums[i+1]);
        }

        int curMax = nums[0];
        long long curMaxScore = 0;
        for(int i = 1 ; i < n - 1 ; i++){
            long long curScore = ((long long)curMax - (long long)nums[i])*((long long)sufMax[i]);
            curMaxScore = max(curMaxScore,curScore);
            curMax = max(curMax,nums[i]);
        }

        return curMaxScore;
        
    }
};