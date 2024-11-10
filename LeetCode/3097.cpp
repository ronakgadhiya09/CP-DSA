class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<vector<int>> pre_or(n+1,vector<int>(32,0));

        // if(nums[0]>=k) return 1;
        // for(int i = 0 ; i < 32 ;i++) if(nums[0]&(1<<i)) pre_or[0][i]++;

        for(int i = 0 ; i < n ; i++){
            if(nums[i]>=k) return 1;
            for(int j = 0 ; j < 32 ; j++){
                if(nums[i] & (1<<j)){
                    pre_or[i+1][j] = pre_or[i][j] + 1;
                }
                else{
                    pre_or[i + 1][j] = pre_or[i][j];
                }
            }
        }

        int l = 1;
        int x = 0;
        int ans = INT_MAX;
        for(int r = 0 ; r < n + 1; r++){
            // cout << nums[r-1] << " " << r  << endl ;
            for(int i = 0 ; i < 32 ;i++){
                if(pre_or[r][i] - pre_or[l-1][i] && !(x & (1<<i))){
                    x |= (1<<i);
                }
            }
            // if(x>=k) ans = min(ans,r-l+1);
            // while(l<=r && x>=k){
            //     for(int i = 0 ; i < 32 ;i++){
            //         if(pre_or[r][i] - pre_or[l][i] == 0 && (x & (1<<i))){
            //             x ^= (1<<i);
            //         }
            //     }
            //     if(x>=k) ans = min(ans,r-l+1);
            //     l++;
            // }
            // if(x>=k) ans = min(ans,r-l+1);

            while(l <= r && x >= k) {
                ans = min(ans, r - l + 1);                
                l++;
                
                x = 0;
                for(int i = 0; i < 32; i++) {
                    if(pre_or[r][i] - pre_or[l - 1][i] > 0) {
                        x |= (1 << i);
                    }
                }
            }
        }

        if(ans==INT_MAX) return -1;
        return ans;
    }
};
