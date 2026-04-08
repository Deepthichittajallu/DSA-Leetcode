class Solution {
public:
const int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        for(long long i=0;i<queries.size();i++)
        {
            long long l = queries[i][0];
            long long r = queries[i][1];
            long long k = queries[i][2];
            long long v = queries[i][3];
            while(l <= r)
            {
                nums[l] = (1LL*nums[l]*v) % mod;
                l += k;
            }
        }
        for(auto it:nums)
        {
            ans =ans^it;
        }
        return ans;
    }
};