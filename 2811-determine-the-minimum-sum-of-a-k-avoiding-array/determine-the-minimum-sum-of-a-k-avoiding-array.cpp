class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int>v,v1;
        int sum = 0;
        if(n>k/2)
        {
            int i=0;
            for(int i=1;i<=k/2;i++)
            {
                v.push_back(i);
                sum+=i;
            }
            for(int i = 0;i<(n-(k/2));i++)
            {
                v.push_back(i+k);
                sum+=(i+k);
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                v1.push_back(i);
                sum+=i;
            }
            // return sum;
        }
        for(auto it:v)
        {
            cout<<it<<" ";
        }
        return sum;
    }
};