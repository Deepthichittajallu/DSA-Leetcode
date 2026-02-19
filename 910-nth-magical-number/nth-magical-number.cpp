class Solution {
public:
const int mod = 1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        long long low = min(a,b);
        long long high = n*1LL*min(a,b);
        long long ans = 0;
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long x = mid / a;
            long long y = mid / b;
            long long z = (a*b) / __gcd(a,b);
            long long inter = mid/z;
            long long cnt = x + y - inter;
            if(cnt < n)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid-1;
            }
        }
        return ans%mod;
    }
};