class Solution {
public:
int sum (vector<int>&temp)
{
    int res =0;
    for(auto it:temp)
    {
        res += it;
    }
    return res;
}
    int sumFourDivisors(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        vector<vector<int>>v;
        for(auto it:mp)
        {
            vector<int>temp;
            for(int i=1;i<=(it.first/2);i++)
            {
                if(it.first%i == 0)
                {
                    temp.push_back(i);
                }
            }
            temp.push_back(it.first);
            v.push_back(temp);
        }
        int ans = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].size() == 4)
            {
                int n = v[i].size();
                ans += (sum(v[i])*mp[v[i][n-1]]);
            }
        }
        return ans;
    }
};