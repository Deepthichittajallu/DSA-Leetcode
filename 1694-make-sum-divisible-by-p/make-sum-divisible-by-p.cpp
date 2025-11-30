class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum  = 0;
        for(auto it:nums)
        {
            sum += it;
        }
        if(sum < p) return -1;
        if(sum%p == 0) return 0;
        long long rem = sum%p;
        long long pre = 0;
        map<int,int>mp;
        mp[0] = -1;
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            pre += nums[i];
            int temp = (pre % p);
            int temp1 = (temp - rem + p) % p;
            if(mp.count(temp1))
            {
                ans = min(ans,i-mp[temp1]);
            }
            mp[temp] = i;
        }
        if(ans == INT_MAX || ans == nums.size()) return -1;
        return ans;
    }
};