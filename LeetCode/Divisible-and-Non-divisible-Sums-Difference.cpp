class Solution {
public:
    int differenceOfSums(int n, int m) {
        int not_divisible = 0;
        for(int i = m ; i <= n ;i+=m){
            not_divisible += i;
        }
        return n*(n+1)/2 - 2*not_divisible;
    }
};