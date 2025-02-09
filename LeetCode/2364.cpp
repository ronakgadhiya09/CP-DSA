class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long,long long> good_group;
        long long n = nums.size();
        for(int i = 0 ; i < n ; i++){
            good_group[nums[i] - i]++;
        }

        long long good = 0;
        for(auto &[key,val] : good_group){
            good += (val*(val-1))/2;
        }
        
        long long total = (n*(n-1))/2;
        return total - good;
    }
};
