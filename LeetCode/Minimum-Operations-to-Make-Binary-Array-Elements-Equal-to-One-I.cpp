class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0;
        int count = 0;
        
        while(l<=n-3){
            
            if(nums[l]==1){
                l++;
                continue;
            }
            
            count++;
            for(int j = l ; j<l+3;j++){
                nums[j] = 1 - nums[j];
            }
            
            l++;
        }
        
        bool flag = true;
        for(int i : nums){
            if(!i){
                flag = false;
                break;
            }
        }
        
        if(!flag){
            return -1;
        }
        
        return count;
    }
};