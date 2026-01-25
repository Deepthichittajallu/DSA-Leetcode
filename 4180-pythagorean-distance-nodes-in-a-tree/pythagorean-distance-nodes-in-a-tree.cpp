class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        vector<int>v1 = bfs(adj,n,x);
        vector<int>v2 = bfs(adj,n,y);
        vector<int>v3 = bfs(adj,n,z);
        for(int i=0;i<n;i++)
        {
            int a = v1[i];
            int b = v2[i];
            int c = v3[i];
            vector<int>temp = {a,b,c};
            sort(temp.begin(),temp.end());
            if(1LL* temp[0]*temp[0] + 1LL*temp[1]*temp[1] == 1LL*temp[2]*temp[2]) cnt++;
        }
        return cnt;
    }
    vector<int>bfs(vector<vector<int>>& adj, int n, int x)
    {
        vector<int>vis(n,0);
        vector<int>dis(n);
        queue<pair<int,int>>q;
        q.push({x,0});
        dis[x] = 0;
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            if(vis[top.first] == 1) continue;
            vis[top.first] = 1;
            dis[top.first] = top.second;
            for(auto it:adj[top.first])
            {
                q.push({it,top.second+1});
            }
        }
         return dis;
    }
};