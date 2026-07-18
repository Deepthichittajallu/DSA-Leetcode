class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        int x = 1;
        for(int x = 0;x <= 1e5;x++)
        {
            if((abs(n-x) <= k) && (n&x) == 0)
            {
                ans += x;
            }
        }
        return ans;
    }
};