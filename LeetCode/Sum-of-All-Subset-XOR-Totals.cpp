class Solution {
private:
    void helper(vector<int> &nums,int index,int xorr,int n,int &sum){
        if(index == n){
            sum += xorr;
            return;
        }

        xorr ^= nums[index];
        helper(nums,index+1,xorr,n,sum);
        xorr ^= nums[index];
        helper(nums,index+1,xorr,n,sum);
    }


public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        helper(nums,0,0,nums.size(),ans);

        return ans;
    }
};