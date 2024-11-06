class Solution {
public:
    bool canSortArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> set_bits(n,0);
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < 32 ;j++){
                if(nums[i]&(1<<j)) set_bits[i]++;
            }
        }

        // for(int i = 0 ; i < n ;i++){
        //    cout << set_bits[i] << " ";
        // }
        cout << endl;
        int prevMax = -1;
        // int prevMin = nums[0];

        int curMax = nums[0];
        int curMin = nums[0];

        for(int i = 0 ; i < n ;){
            int l = i;
            curMax = nums[i];
            curMin = nums[i];
            while(l < n && set_bits[i]==set_bits[l]){
                curMax = max(curMax,nums[l]);
                curMin = min(curMin,nums[l]);
                l++;
            }

            // cout << "current Max : " << curMax << endl;
            // cout << "current Min : " << curMin << endl;

            if(curMin < prevMax) return false;

            prevMax = curMax;
            // prevMin = curMin;
            i = l;
        }

        return true;
    }
};
