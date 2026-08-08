class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++)
        {
            int u = pre[i][0];
            int v = pre[i][1];
            adj[v].push_back(u);
        }
        vector<int>ind(n);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                ind[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<ind.size();i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                ind[it]--;
                if(ind[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if(topo.size() == n) return true;
        return false;
    }
};