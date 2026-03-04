class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int cnt=0;
        set<pair<int,int>>s1;
        for(int i=0;i<nums.size();i++)
        {
            s1.insert({nums[i],i});
        }
        while(!s1.empty())
        {
            auto t1=*s1.begin();
            s1.erase(t1);
            auto t2=*s1.begin();
            auto idx1=t1.second;
            auto idx2=t2.second;
            if(idx1==idx2) break;
            if(t1.first==t2.first && abs(idx1-idx2)<=k)
            {
                return true;
            }
           
        }
         return false;
    }
};