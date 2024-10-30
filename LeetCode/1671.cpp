class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();

        vector<int> dpf(n+1,1);
        vector<int> dpb(n+1,1);
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= i - 1 ; j++){
                if(nums[j-1]<nums[i-1]){
                    dpf[i] = max(dpf[i],dpf[j] + 1);
                }
            }   
        }

        for(int i = n ; i >= 1 ;i--){
            for(int j = n ; j > i ;j--){
                if(nums[j-1] < nums[i-1]){
                    dpb[i] = max(dpb[i],dpb[j] + 1);
                }
            }
        }

        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            if(dpf[i]>=2 && dpb[i]>=2)
                ans = max(ans,dpf[i]+dpb[i]-1);
        }

        return n - ans;
    }   
};
