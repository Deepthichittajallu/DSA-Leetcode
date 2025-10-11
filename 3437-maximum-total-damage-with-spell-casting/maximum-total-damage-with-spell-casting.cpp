class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        long long n = power.size();
        map<long long,long long>mp;
        for(long long i=0;i<power.size();i++)
        {
            mp[power[i]]++;
        }
        vector<pair<long long,long long>>v;
        for(auto it:mp)
        {
            v.push_back({it.first,it.second});
        }
        sort(v.rbegin(),v.rend());
        vector<long long>dp(v.size(), 0);
        dp[0] = v[0].first*v[0].second;
        // for(auto it:v)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(long long i=1;i<v.size();i++)
        {
            long long j = i-1;
            long long x = 0;
            while(j>=0)
            {
                if((v[i].first)+3 <= v[j].first)
                {
                    x = dp[j];
                    break;
                }
                else
                {
                    j--;
                }
            }
            dp[i] = max(x+(v[i].first*v[i].second),dp[i-1]);
            // cout << (x+(v[i].first*v[i].second)) << " " <<  x  << " " << dp[i - 1] << '\n';
        }
        // for(auto it:dp)
        // {
        //     cout<<it<<" ";
        // }
        return dp[v.size()-1];

    }
};