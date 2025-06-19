class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int curLeft = nums[0];
        int ans = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] - curLeft > k){
                ans++;
                curLeft = nums[i];
            }
        }   
        return ans;
    }
};