class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        unordered_set<int> numbersInArr(arr.begin(),arr.end());
        int maxi = 2;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int curSize = 2;
                int sum = arr[i] + arr[j];
                int temp = arr[i];
                while(numbersInArr.find(sum)!=numbersInArr.end()){
                    curSize++;
                    int nextTerm = sum;

                    sum -= temp;
                    temp = sum;
                    sum += nextTerm;
                }

                maxi = max(maxi,curSize);
            }
        }

        return maxi>2 ? maxi : 0;
    }
};
