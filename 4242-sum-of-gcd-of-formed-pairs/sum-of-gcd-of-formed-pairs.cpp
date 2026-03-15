class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        // cout<<maxi;
        vector<long long>pre(n,0);
        for(long long i=0;i<n;i++)
            {
                maxi = max(maxi,nums[i]);
                pre[i] = maxi;
            }
        for(int i=0;i<n;i++)
            {
                pre[i] = __gcd((int)pre[i],(int)nums[i]);
            }
        sort(pre.begin(),pre.end());
        // for(auto it:pre)
        //     {
        //         cout<<it<<" ";
        //     }
        long long sum = 0;
        long long l= 0;
        long long r = n-1;
        while(l<r)
            {
                sum += gcd(pre[l],pre[r]);
                l++;
                r--;
            }
        return sum;
    }
};