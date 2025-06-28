class Solution {
public:
    static bool comp(const pair<int,int> &a, const pair<int,int> &b){
        return a.second < b.second;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> temp;

        for(int i = 0 ; i < n ; i++){
            temp.push_back({nums[i],i});
        }

        sort(temp.begin(),temp.end(),greater<pair<int,int>>());
        for(int i = 0 ; i < n - k ; i++) temp.pop_back();

        sort(temp.begin(),temp.end(),comp);
       
        vector<int> ans;
        for(auto &[val,ind] : temp) ans.push_back(val);

        return ans;
    }
};