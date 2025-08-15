class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 0) return false;
        int setBitCount = 0;
        int lastSetBit = -1;

        for(int i = 0 ; i < 31 ; i++){
            if(n & 1<<i){
                setBitCount++;
                lastSetBit = i;
            }
        }

        return (setBitCount==1 && lastSetBit%2==0);
    }
};