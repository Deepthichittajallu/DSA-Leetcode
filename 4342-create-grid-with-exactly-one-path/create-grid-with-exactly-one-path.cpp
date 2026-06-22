class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>>temp(m,vector<char>(n,'.'));
        vector<string>res;
        for(int i=1;i<m;i++)
        {
            for(int j = 0;j<n-1;j++)
            {
                temp[i][j] = '#';
            }
        }
        for(auto it:temp)
        {
            string tempo = "";
            for(auto i:it)
            {
                tempo += i;
            }
            res.push_back(tempo);
        }
        return res;
    }
};