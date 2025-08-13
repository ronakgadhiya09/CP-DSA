class Solution {
    const int x = 1162261467; // 3^19 -> largest pow of 3 < 2^31
public:
    bool isPowerOfThree(int n) {
        if(n<=0 || x%n) return false;
        return true;
    }
};