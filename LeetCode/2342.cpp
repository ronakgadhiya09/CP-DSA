class Solution {

private:
    int sumOfDigits(int num){
        int sum = 0;
        while(num){
            int x = num%10;
            num /= 10;
            sum += x;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {

        unordered_map<int,vector<int>> numsWithDigitSum;

        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int digitSum = sumOfDigits(nums[i]);
            numsWithDigitSum[digitSum].push_back(nums[i]);
        }
        
        // for(auto &[digitSum,v] : numsWithDigitSum){
        //     cout << digitSum << " : ";
        //     for(auto &num : v){
        //         cout << num << " ";
        //     }
        //     cout << endl;
        // }


        int maxSum = -1;
        for(auto &[digitSum,v] : numsWithDigitSum){
            int top = 0;
            int secondtop = -1;
            if(v.size()>=2){
                for(auto &num : v){
                    if(num >= top){
                        secondtop = top;
                        top = num;
                    }
                    else if(num > secondtop){
                        secondtop = num;
                    }
                }
            }

            maxSum = max(maxSum,top + secondtop);
        }

        return maxSum;
    }
};
