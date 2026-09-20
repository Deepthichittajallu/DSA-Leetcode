class Solution {
public:
    int reverseDegree(string s) {
        int prod=0;
        vector<int>v;
        for(int i=0;i<s.size();i++)
        {
            int res=s[i];
            int ans=res-(71+(2*(res-97)));
          // v.push_back(ans*(i+1));
            prod+=ans*(i+1);
        }
        for(auto it:v)
        {
            cout<<it<<" ";
        }
        return prod;
    }
};