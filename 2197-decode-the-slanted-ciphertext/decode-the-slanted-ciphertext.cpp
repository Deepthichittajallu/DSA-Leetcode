class Solution {
public:
    string decodeCiphertext(string str, int rows) {
        vector<vector<char>>v;
        int cnt = 0;
        for(int i = 0;i<rows;i++)
        {
            vector<char>temp;
            for(int j=0;j<(str.size()/rows);j++)
            {
                temp.push_back(str[cnt++]);
            }
            v.push_back(temp);
        }
        int i = 0 , j = 0;
        cnt = 0;
        string ans = "";
        int col = str.size() / rows;
        while(cnt < col)
        {
            i = 0;
            j = cnt;
            while(i < rows && j < col)
            {
                ans += v[i++][j++];
            }
            cnt++;
        }
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i] == ' ') ans.pop_back();
            else break;
        }
        return ans;
    }
};