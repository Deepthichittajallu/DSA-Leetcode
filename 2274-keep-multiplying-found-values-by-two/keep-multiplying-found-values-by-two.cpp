class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        while(true)
        {
            if(mp[original] >= 1)
            {
                original = original*2;
            }
            else
            {
                break;
            }
        }
        return original;
    }
};