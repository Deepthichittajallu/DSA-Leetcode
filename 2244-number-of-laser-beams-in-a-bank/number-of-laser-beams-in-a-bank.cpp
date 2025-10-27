class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;
        int ocnt = 0;
        for(int i=0;i<bank.size();i++)
        {
           ocnt = 0;
           for(int j=0;j<bank[i].size();j++)
           {
            if(bank[i][j] == '1') ocnt++;
           }
           if(ocnt > 0)
           {
            ans += ocnt * prev;
            prev = ocnt;
           }
        }
        return ans;
    }
};