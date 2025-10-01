class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int a = numBottles;
        int b = numBottles;
       while(b >=  numExchange)
       {
        int rem = b/numExchange;
        a+=rem;
        b = (b%numExchange)+rem;
       }
       return a;
    }
};