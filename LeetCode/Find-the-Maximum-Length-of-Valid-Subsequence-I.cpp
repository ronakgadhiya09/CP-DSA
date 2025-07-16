class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> v1; 
        vector<int> v2; 
        vector<int> v3; 
        vector<int> v4;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 1) { 
                v1.push_back(nums[i]);
            } else { 
                v2.push_back(nums[i]);
            }
            
            if ((v3.empty() && nums[i] % 2 == 1) || (!v3.empty() && (v3.back() + nums[i]) % 2 == 1)) {
                v3.push_back(nums[i]);
            }
            if ((v4.empty() && nums[i] % 2 == 0) || (!v4.empty() && (v4.back() + nums[i]) % 2 == 1)) {
                v4.push_back(nums[i]);
            }
        }
        
        int max_length = max(max(v1.size(), v2.size()), max(v3.size(), v4.size()));
        
        return max_length;
    }
};
