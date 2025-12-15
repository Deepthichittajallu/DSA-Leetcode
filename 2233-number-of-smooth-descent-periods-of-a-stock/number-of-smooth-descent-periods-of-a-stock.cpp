class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        bool found = true;
        long long cnt = 1;
        long long ans = 0;
        for(long long i = 1;i<prices.size();i++)
        {
            if(prices[i-1] - prices[i] == 1 && found  == true)
            {
                cnt++;
            }
            else
            {
                ans += (cnt*(cnt+1))/2;
                cnt = 1;
            }
        }
        ans += (cnt*(cnt+1))/2;
        return ans;
    }
};