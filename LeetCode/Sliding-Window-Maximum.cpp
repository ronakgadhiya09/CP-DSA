class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(i < k){
                ms.insert(nums[i]);
                if(i == k-1) ans.push_back(*ms.rbegin());
            }
            else{
                auto prev  = ms.find(nums[i-k]);
                ms.erase(prev);
                ms.insert(nums[i]);
                ans.push_back(*ms.rbegin());
            }
        }
        return ans;
    }
};