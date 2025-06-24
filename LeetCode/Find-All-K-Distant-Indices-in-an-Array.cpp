class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        int l = -1;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == key){
                for(int j = max(l+1,i-k) ; j <= min(n-1,i+k) ;j++){
                    ans.push_back(j);
                    l = j;
                }
            }
        }
        return ans;
    }
};