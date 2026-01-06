class Solution {
public:
    double angleClock(int hour, int minutes) {
        double tempo =  abs(30.0 * hour - (5.5) * minutes);
        double temp = 360.0 - tempo;
         return min(temp,tempo);
    }
};