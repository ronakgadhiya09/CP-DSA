class Solution {
public:
    int largestCombination(vector<int>& candidates) {

        vector<int> set_bits(32,0);

        for(auto &num : candidates){
            for(int i = 0 ; i < 32 ;i++){
                if((num & (1<<i))) set_bits[i]++;
            }
        }
        
        int n = candidates.size();
        int maxi = 0;
        for(int i = 0 ; i < 32 ;i++){
            maxi = max(maxi,set_bits[i]);
        }
        
        return maxi;
    }
};
