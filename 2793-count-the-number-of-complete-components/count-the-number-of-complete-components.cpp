class Solution {
public:
vector<vector<int>>temp;
// int cnt = 0;
void bfs(vector<bool>&vis,vector<vector<int>>& edges,int node)
{
    vector<int>row;
    vis[node] = true;
    queue<int>pq;
    pq.push(node);
    while(!pq.empty())
    {
        auto top = pq.front();
        row.push_back(top);
        pq.pop();
        for(auto it:edges[top])
        {
            if(!vis[it])
            {
                vis[it] = true;
                pq.push(it);
            }
        }
    }
    temp.push_back(row);
}
int check(vector<vector<int>>&temp,vector<vector<int>>&adj)
{
    int cnt = 0;
    for(int i=0;i<temp.size();i++)
    {
         bool found = false;
        for(int j=0;j<temp[i].size();j++)
        {
            int ele = temp[i][j];
            if(adj[ele].size() != temp[i].size() - 1) 
            {
                found = true;
                break;
            }
        }
        if(found == false) cnt++;
        
    }
    return cnt;
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // int n = edges.size();
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // for(int i=0;i<adj.size();i++)
        // {
        //     for(auto it:adj[i])
        //     {
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<bool>vis(n,false);
        // int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                bfs(vis,adj,i);
                //   if(check(temp,adj) == true) cnt++;
            }
        }
        int ans = 0;
        ans = check(temp,adj);
        return ans;
    }
};