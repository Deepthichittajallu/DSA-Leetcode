// class Solution {
// public:
//     int triangularSum(vector<int>& nums) {
//         vector<vector<int>>res;
//         res.push_back(nums);
//         int n = nums.size();
//         for(int i=0;i<n-1;i++)
//         {
//             vector<int>row(0,n-1-i);
//             for(int j=0;j<n-i-1;j++)
//             {
//                 row[j] = (res[i-1][j]+res[i-1][j+1])%10;
//             }
//             res.push_back(row);
//         }
//         for(int i=0;i<res.size();i++)
//         {
//             for(int j=0;j<res[i].size();j++)
//             {
//                 cout<<res[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         return 0;
//     }
// };
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            vector<int>row(n-i,0);
            for(int j=0;j<n-i;j++)
            {
                row[j] = 0;
            }
            res.push_back(row);
        }
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[i].size();j++)
            {
                if(i==0)
                {
                    res[i][j] = nums[j];
                }
                else
                {
                    res[i][j] = (res[i-1][j] + res[i-1][j+1])%10;
                }
            }
        }
        // for(int i=0;i<res.size();i++)
        // {
        //     for(int j=0;j<res[i].size();j++)
        //     {
        //         cout<<res[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = res[n-1].size();
        return res[n-1][ans-1];
    }
};