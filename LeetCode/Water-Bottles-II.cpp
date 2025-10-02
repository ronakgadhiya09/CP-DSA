class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottlesDrank = numBottles;
        int exchangeFactor = numExchange;
        int emptyBottles = numBottles;

        while(emptyBottles >= exchangeFactor){
            emptyBottles -= exchangeFactor;
            exchangeFactor++;
            bottlesDrank++;
            emptyBottles++;
        }
        
        return bottlesDrank;
    }
};