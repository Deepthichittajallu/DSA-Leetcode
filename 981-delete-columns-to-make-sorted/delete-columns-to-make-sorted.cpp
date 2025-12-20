class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int cnt = 0;
        for(int i=0;i<strs[0].size();i++)
        {
            string temp = "";
            for(int j = 0;j<strs.size();j++)
            {
                temp += strs[j][i];
            }
            string temp1 = temp;
            sort(temp1.begin(),temp1.end());
            if(temp1 != temp) cnt++;
        }
        return cnt;
    }
};