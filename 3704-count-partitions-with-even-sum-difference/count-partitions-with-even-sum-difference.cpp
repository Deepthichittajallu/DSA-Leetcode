class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<int>pre(n,0);
        int cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            pre[i] = nums[i];
        }
        for(int i=0;i<n;i++)
        {
            int temp = abs(sum - (2*pre[i]));
            if(temp%2==0) cnt++;
        }
        return (cnt>0 ? cnt-1 : 0);
    }
};