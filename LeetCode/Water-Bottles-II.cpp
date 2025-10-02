class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottlesDrank = numBottles;
        int exchangeFactor = numExchange;
        int emptyBottles = numBottles;

        int round = 1;
        while(emptyBottles >= exchangeFactor){
            emptyBottles -= exchangeFactor;
            exchangeFactor++;
            bottlesDrank ++;
            emptyBottles++;
        }
        
        return bottlesDrank;
    }
};