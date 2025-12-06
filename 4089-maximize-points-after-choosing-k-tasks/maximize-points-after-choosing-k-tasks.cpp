class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        vector<pair<int,int>>v1;
        vector<pair<int,int>>v2;
       long long sum = 0;
        if(k==0)
        {
            for(int i=0;i<t1.size();i++) sum += max(t1[i],t2[i]);
            return sum;
        }
        for(int i=0;i<t1.size();i++)
        {
            if(t1[i] > t2[i])
            {
                v1.push_back({t1[i],t2[i]});
            }
        }
        sort(v1.begin(),v1.end(),greater<>());
        // for(auto it:v1)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(int i=0;i<t1.size();i++)
        {
            if(t2[i] >= t1[i])
            {
                v2.push_back({t2[i] - t1[i], i}); 
            }
        }
        sort(v2.begin(),v2.end());
        int pos = -1;
        for(int i=0;i<k&&i<v1.size();i++)
        {
            sum += v1[i].first;
            pos = i;
        }
        if(v1.size() > k)
        {
            for(int i = k;i<v1.size();i++)
            {
                sum += max(v1[i].first,v1[i].second);
            }
            for(int i=0;i<v2.size();i++)
            {
                sum += t2[v2[i].second];
            }
        }
        // cout<<sum<<endl;
        if(v1.size() <= k)
        {
            int n = k - v1.size();
            for(int i=0;i<n;i++)
            {
                sum += t1[v2[i].second];
                cout<<sum;
            }
           for(int i=n;i<v2.size();i++)
           {
            sum += t2[v2[i].second];
           }
        }

        return sum;
    }
};