class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>v;
        for(auto it:mp)
        {
            v.push_back(it.second);
        }
        int maxi = *max_element(v.begin(),v.end());
        int sum = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i] == maxi)
            {
                sum+=v[i];
            }
        }
        return sum;
    }
};