class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s(nums.begin(),nums.end());
        int smallestNum = *s.begin();
        if(k < smallestNum) return s.size();
        else if(k == smallestNum) return s.size() - 1;        
        return -1;
    }
};