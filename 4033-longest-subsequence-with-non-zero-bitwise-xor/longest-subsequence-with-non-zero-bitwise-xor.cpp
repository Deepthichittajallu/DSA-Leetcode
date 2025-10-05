class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int cnt = 1;
        int xo = nums[0];
        int x = 0;
        map<int,int>mp;
        if(nums.size() == 1 && nums[0] == 0) return 0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            x = (x^nums[i]);
        }
        // for(auto it:mp)
        // {
        //     cout<<it.first;
        // }
        if(mp.size() == 1 && nums[0] > 0)
        {
            if(nums.size()%2 == 0) return nums.size()-1;
            else return nums.size();
        }
        else if(mp.size() == 1 && nums[0] == 0) return 0;
        else if(x!=0)
        {
            return nums.size();
        }
        else{
        for(int i=1;i<nums.size();i++)
        {
            if((nums[i]^xo)!=0) 
            {
                cnt++;
                xo = (xo^nums[i]);
            }
            else
            {
                continue;
            }
        }
        }
        return cnt;
    }
};