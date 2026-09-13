class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
         map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        int cnt = 0;
        for(auto it:mp)
        {
            if(it.second.size() < 3) continue;
            else if(it.second.size() >= 3)
            {
                map<int,int>temp;
                auto vec = it.second;
                for(int i=1;i<vec.size();i++)
                {
                    temp[vec[i]-vec[i-1]]++;
                }
                if(temp.size() == 1) cnt++;
            }
        }
        return cnt;
    }
};