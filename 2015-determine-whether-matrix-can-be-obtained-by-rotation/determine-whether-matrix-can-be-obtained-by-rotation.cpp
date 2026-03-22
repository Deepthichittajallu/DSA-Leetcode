class Solution {
public:
bool fun(vector<vector<int>>& mat,vector<vector<int>>& target)
{
        int l = 0;
        int r = mat.size() - 1;
         while(l < r)
        {
            swap(mat[l++],mat[r--]);
        }
        int m = mat.size();
        int n = mat[0].size();
    vector<vector<int>>temp(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                temp[i][j] = mat[j][i];
            }
        }
        mat = temp;
        if(mat == target) return true;
        return false;
}
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool r1 = fun(mat,target);
        // print(mat);
        bool r2 = fun(mat,target);
        bool r3 = fun(mat,target);
        bool r4 = fun(mat,target);
        cout<<r1<<" "<<r2<<" "<<r3<<" "<<r4; 
        return (r1 || r2 || r3 || r4);
    }
};