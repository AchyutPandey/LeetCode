class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int left=0;
        while(numBottles>=numExchange){
            
            left=numBottles%numExchange;
            numBottles=numBottles/numExchange;
            ans+=numBottles;
            numBottles+=left;
        }
        return ans;
    }
};