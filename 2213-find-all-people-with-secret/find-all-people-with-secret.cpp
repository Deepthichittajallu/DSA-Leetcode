class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),[](const vector<int>&a,const vector<int>&b)
        {
            return a[2]<b[2];
        });
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<meetings.size();i++)
        {
            int u = meetings[i][0];
            int v = meetings[i][1];
            int t = meetings[i][2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        queue<pair<int,int>>q;
        set<int>st;
        q.push({0,0});
        q.push({firstPerson,1});
        st.insert(0);
        st.insert(firstPerson);
        vector<int>vis(n,INT_MAX);
        vis[0] = 0;
        vis[firstPerson] = 1;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int person = it.first;
            int time = it.second;
            for(auto it:adj[person])
            {
                if(time <= it.second && vis[it.first] > it.second)
                {
                    q.push({it.first,it.second});
                    st.insert(it.first);
                    vis[it.first] = it.second;
                }
            }
        }
        vector<int>res(st.begin(),st.end());
        return res;
    }
};