class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>res;
        int i=0;
        while(n!=0)
        {
            int rem = n%10;
            // if(rem == 0) continue;
            res.push_back(rem*(pow(10,i)));
            i++;
            n/=10;
        }
        vector<int>v1;
        for(int i=0;i<res.size();i++)
        {
            if(res[i] == 0) continue;
            else v1.push_back(res[i]);
        }
        reverse(v1.begin(),v1.end());

        return v1;
    }
};