class Solution {
public:
    int nextGreaterElement(int n) {
        vector<long long>nums;
        long long temp = n;
        while(n!=0)
        {
            nums.push_back(n%10);
            n=n/10;
        }
        long long size = nums.size();
        long long j=0;
        long long i=j+1;
        // while(i<size && j<size)
        // {
        //     if(nums[j] > nums[i])
        //     {
        //         long long temp = nums[i];
        //         nums[i] = nums[j];
        //         nums[j] = temp;
        //         break;
        //     }
        //     else
        //     {
        //         j++;
        //         i=j+1;
        //     }
        // }
        reverse(nums.begin(),nums.end());
        next_permutation(nums.begin(),nums.end());
        for(auto it:nums)
        {
            cout<<it<<" ";
        }
        long long ans = 0;
        for(long long i=0;i<nums.size();i++)
        {
            ans=(ans * 10 +nums[i]);
        }
        if(ans <= temp || ans > INT_MAX) return -1;
        return (int)ans;
    }
};