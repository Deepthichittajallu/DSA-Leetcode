class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int>ass(n,0);
        for(int i=0;i<customers.size();i++)
        {
            if(customers[i] == 'Y') ass[i] = 1;
        }
        vector<int>yes(n,0);
        vector<int>no(n,0);
        int sum = 0;
       for(int i=0;i<n;i++)
       {
        if(ass[i] == 1)
        {
            sum++;
        }
        yes[i] = sum;
       }
        int sum2 = 0;
         for(int i=0;i<n;i++)
        {
            if(ass[i] == 0)
            {
                sum2++;
            }
            no[i] = sum2;
        }
        vector<int>res(n+1,0);
        res[0] = sum;
        for(int i=1;i<=n;i++)
        {
            res[i] = sum - yes[i-1] + no[i-1];
        }
        // for(auto it:res) cout<<it<<" ";
        int ans = *min_element(res.begin(),res.end());
        for(int i=0;i<res.size();i++)
        {
            if(res[i] == ans) return i;
        }
        return 0;
    }
};