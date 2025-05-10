class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        long long sum1 = 0,sum2 = 0;
        int zero1 = 0,zero2 = 0;
        for(int i = 0 ; i < n1 ;i++){
            sum1 += nums1[i];
            if(!nums1[i]) zero1++;
        }
        for(int i = 0 ; i < n2 ;i++){
            sum2 += nums2[i];
            if(!nums2[i]) zero2++;
        }

        cout << "sum1 & sum2 are : " << sum1 << ", " << sum2 << endl;
        cout << "zero1 & zero2 are : " << zero1 << ", " << zero2 << endl;

        if(zero1 && zero2){
            return max(sum1 + zero1,sum2 + zero2);
        }
        else if(!zero1 && zero2){
            return sum2 + zero2 > sum1 ? -1 : sum1;
        }
        else if(zero1 && !zero2){
            return sum1 + zero1 > sum2 ? -1 : sum2;
        }
        
        return sum1 == sum2 ? sum1 : -1;
    }
};