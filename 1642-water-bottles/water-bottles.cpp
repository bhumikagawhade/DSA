class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink = numBottles;
        while(numBottles >= numExchange){
            int remain = numBottles%numExchange;

            numBottles = numBottles/numExchange;

            drink = drink + numBottles;
            // if(numBottles < numExchange){
                numBottles+=remain;
            //}

        }

        return drink;
    }
};