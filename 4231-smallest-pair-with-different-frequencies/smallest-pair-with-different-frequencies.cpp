class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        sort(nums.begin(),nums.end());
        int a = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(a!=nums[i] && mp[a] != mp[nums[i]])
            {
                return {a,nums[i]};
            }
        }
        return {-1,-1};
    }
};