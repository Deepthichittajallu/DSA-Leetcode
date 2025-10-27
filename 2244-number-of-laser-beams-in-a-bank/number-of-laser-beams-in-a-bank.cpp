class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int ocnt = 0;
        vector<int>v;
        int k=0;
        for(int i=0;i<bank.size();i++)
        {
           ocnt = 0;
           for(int j=0;j<bank[i].size();j++)
           {
            if(bank[i][j] == '1') ocnt++;
           }
           if(ocnt>=1)v.push_back(ocnt);
           if(v.size() > 1 && ocnt >= 1)
           {
            cout<<ocnt<<" ";
            ans += ocnt*(v[k]);
            k++;
           }
        }
        return ans;
    }
};