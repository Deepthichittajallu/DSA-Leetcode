class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt= 0;
        for(int i=0;i<n;i++)
        {
            auto it = upper_bound(nums.begin(),nums.end(),nums[i]);
            int temp = nums.end() - it;
            if(temp >= k) cnt++;
        }
        return cnt;
    }
};