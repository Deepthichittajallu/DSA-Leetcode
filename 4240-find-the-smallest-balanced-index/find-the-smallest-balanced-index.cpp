class Solution {
public:
const int mod = 1e9+7;
    int smallestBalancedIndex(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0, pro = 1;
        vector<long long>pre(n,0);
        vector<long long>prod(n,1);
        for(long long i=0;i<n;i++)
        {
            sum += (nums[i]%mod);
            sum = sum%mod;
            pre[i] =(sum%mod);
        }
        for(long long i=n-1;i>=0;i--)
        {
            pro *= (nums[i]%mod);
            pro = pro%mod;
            prod[i] = pro%mod;
        }
        for(long long i=1;i<n-1;i++)
        {
            if(pre[i-1] == prod[i+1]) 
            {
                return i;
            }
        }
        if(n==2)
        {
            if(nums[0] == 1) return 1;
            else if(nums[1] == 0) return 0;
        }
        return -1;
    }
};