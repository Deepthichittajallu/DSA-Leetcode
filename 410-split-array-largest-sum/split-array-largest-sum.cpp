class Solution {
public:
int isValid(vector<int>& nums,int mid)
{
    int sum = 0;
    int cnt = 1;
    for(int i=0;i<nums.size();i++)
    {
        if(sum + nums[i] <= mid)
        {
            sum += nums[i];
        }
        else
        {
            cnt++;
            sum = nums[i];
        }
    }
    return cnt;
}
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = INT_MAX;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(isValid(nums,mid) <= k)
            {
                ans = mid;
                high = mid -1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};