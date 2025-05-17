class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;

        for(auto &num : nums){
            if(num == 0) zero++;
            else if(num == 1) one++;
            else two++;
        }

        nums.clear();
        nums.insert(nums.end(), zero, 0);
        nums.insert(nums.end(), one, 1);
        nums.insert(nums.end(), two, 2);
    }
};