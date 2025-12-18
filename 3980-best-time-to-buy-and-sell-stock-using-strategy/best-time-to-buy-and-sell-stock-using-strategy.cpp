class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long sum = 0;
        for(long long i=0;i<prices.size();i++)
        {
            sum += (prices[i] * strategy[i]);
        }
        long long tempo = sum;
        long long ans = LLONG_MIN;
        long long n = prices.size();
        long long l=0;
        long long mid = k/2;
        long long r = k;
        long long temp1 = 0;
        for(long long i=0;i<k;i++)
        {
            temp1 +=(prices[i]*strategy[i]);
        }
        long long midsum = 0;
        for(long long i = mid;i<r;i++)
        {
            midsum += prices[i];
        }
        sum -= temp1;
        sum += midsum;
        ans = max(ans,sum);
        while(r<n)
        {
            ans = max(ans,sum);
            sum += (prices[l] * strategy[l]);
            l++;
            sum -= (prices[mid]);
            mid++;
            sum -= (prices[r]*strategy[r]);
            sum += prices[r];
            r++;
        }
        ans = max(ans,sum);
        return max(ans,tempo);
    }
};