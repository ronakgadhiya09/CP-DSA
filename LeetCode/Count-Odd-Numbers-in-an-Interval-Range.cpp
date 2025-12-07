1class Solution {
2public:
3    int countOdds(int low, int high) {
4        int width = high - low + 1;
5        if(low&1) return (width + 1)/2;
6        else return width/2;
7    }
8};