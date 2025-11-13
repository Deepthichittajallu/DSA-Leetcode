class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        int res = INT_MAX;
        int mini = INT_MAX;
        for(auto it:mp)
        {
            int n = it.second.size();
            ans = 0;
            for(int i = 0;i<=n-3;i++)
            {
                int a = it.second[i];
                int b = it.second[i+1];
                int c = it.second[i+2];
                ans = abs(a-b)+abs(b-c)+abs(c-a);
                mini = min(ans , mini);
            }
            res = min(mini,res);
        }
        return res == INT_MAX ? -1 : res;
    }
};