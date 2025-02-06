class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        unordered_map<int, int> freq;
        vector<pair<int, int>> numbers;

        int k = nums.size();
        
        for (int i = 0; i < k; i++) {
            for (int num : nums[i]) {
                numbers.push_back({num, i});
            }
        }

        sort(numbers.begin(), numbers.end());
        int n = numbers.size();

        int best_dif = INT_MAX;
        vector<int> best_range = {0, 0};

        int l = 0;
        for (int r = 0; r < n; r++) {
            auto [ele, list_num] = numbers[r];
            freq[list_num]++;

            while (freq.size() == k) {
                auto [ele1, list_num1] = numbers[l];

                if (ele - ele1 < best_dif) {
                    best_dif = ele - ele1;
                    best_range[0] = ele1;
                    best_range[1] = ele;
                }
                freq[list_num1]--;
                if (freq[list_num1] == 0) {
                    freq.erase(list_num1);
                }
                l++;
            }
        }

        return best_range;
    }
};
