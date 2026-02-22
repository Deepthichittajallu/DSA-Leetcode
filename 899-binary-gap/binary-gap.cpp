class Solution {
public:
    int binaryGap(int n) {
        string res = "";
        while(n!=0)
        {
            res += to_string(n%2);
            n/=2;
        }
        reverse(res.begin(),res.end());
        vector<int>temp;
        int maxi = 0;
        for(int i=0;i<res.size();i++)
        {
            if(res[i] == '1') temp.push_back(i);
        }
        for(int i=1;i<temp.size();i++)
        {
            int tempo = temp[i] - temp[i-1];
            maxi = max(maxi,tempo);
        }
        return maxi;
    }
};