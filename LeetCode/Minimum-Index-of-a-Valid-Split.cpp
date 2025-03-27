class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        int n = nums.size();
        int mostFreqEle = nums[0];
        int freq = 0;

        for(int i = 0 ; i < n ; i++){
            if(nums[i]==mostFreqEle){
                freq++;
            }
            else{
                freq--;
            }
            if(freq==0){
                mostFreqEle = nums[i];
                freq = 1;
            }
        }

        freq = 0;
        for(auto &num : nums) if(num == mostFreqEle) freq++;

        cout << freq << endl;
        if(freq < n/2) return -1;

        int cur = 0;
        // cout << freq << endl;
        for(int i = 0 ; i < n - 1; i++){
            if(nums[i]==mostFreqEle) cur++;
            if(cur > (i+1)/2 && (freq - cur) > (n - i - 1)/2){
                // cout << "cur is : " << cur << " i is : " << i << " freq is : " << freq << endl;
                return i;
            }
        }

        cout << "Out of the loop " << endl;
        return -1;
    }
};