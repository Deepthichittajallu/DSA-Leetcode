class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
       vector<vector<int>>v(n,vector<int>(n,0));
       for(int i=0;i<queries.size();i++)
       {
        int a = queries[i][0];
        int b = queries[i][1];
        int c = queries[i][2];
        int d = queries[i][3];
        for(int j=a;j<=c;j++)
        {
            for(int k = b;k<=d;k++)
            {
                v[j][k] += 1;
            }
        }
       }
       return v;
    }
};