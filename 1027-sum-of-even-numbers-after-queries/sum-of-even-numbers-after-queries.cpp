class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(auto it:nums)
        {
            if(it%2 == 0) sum += it;
        }
        vector<int>v;
        for(int i=0;i<queries.size();i++)
        {
            int val = queries[i][0];
            int ind = queries[i][1];
            if(abs(nums[ind]) % 2 == 1 && abs(val) %2 == 1)
            {
                sum += (nums[ind]+val);
                nums[ind] += val;
            }
            else if(abs(nums[ind])%2==0 && abs(val)%2==0)
            {
                sum +=(val);
                nums[ind] += val;
            }
            else if((abs(nums[ind])%2 == 0) && (abs(val)%2 == 1))
            {
                sum -= nums[ind];
                nums[ind] += val;
            }
            else
            {
                nums[ind] += val;
            }
            v.push_back(sum);
        }
        return v;
    }
};