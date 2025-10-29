class Solution {
public:
    int smallestNumber(int n) {
        if(n==1) return 1;
        for(int i = 0;i<n;i++)
        {
            int power = pow(2,i);
            power -= 1;
            if(power >= n)
            {
                return power;
            }
        }
        return 0;
    }
};