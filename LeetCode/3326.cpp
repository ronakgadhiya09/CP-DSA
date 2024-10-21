class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n  = nums.size();
        int op = 0;
        int i = n-2;
        for( ; i >= 0 ; i--){
            bool flag = true;
            while(flag && (nums[i]>nums[i+1])){
                int sq = ceil(sqrt(nums[i]));
                bool check = true;
                for(int j = 2 ; j <= sq ;j++){
                    if(nums[i]%j==0){
                        op++;
                        nums[i] = j;
                        check = false;
                        break;
                    }
                }
                if(check) return -1;
            }
        }
        
        // if(i!=n-1) return -1;
        return op;
    }
};
