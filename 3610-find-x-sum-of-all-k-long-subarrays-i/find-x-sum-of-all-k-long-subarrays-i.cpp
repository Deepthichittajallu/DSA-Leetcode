class Solution {
public:
    int fun(vector<int>&v,int &x)
    {
        int sum = 0;
        map<int,int>mp;
        for(int i=0;i<v.size();i++)
        {
            mp[v[i]]++;
        }
        vector<pair<int,int>>row;
        for(auto it:mp)
        {
            row.push_back({it.second,it.first});
        }
        sort(row.begin(),row.end(),greater<>());
        for(int i=0;i<x&&i<row.size();i++)
        {
            sum += (row[i].first*row[i].second);
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>res;
        for(int i=0;i<nums.size() && i <= nums.size() - k;i++)
        {
            vector<int>temp;
            for(int j = i;j<nums.size() && j<k+i;j++)
            {
                temp.push_back(nums[j]);
            }
            res.push_back(fun(temp,x));
        }
        return res;
    }
};