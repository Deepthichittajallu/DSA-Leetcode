class Solution {
public:
set<string>ans;
void fun(int n,int k,int i,string temp)
{
    if(i == n)
    {
        int sum = 0;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i] == '1') sum += i;
        }
        if(sum <= k) ans.insert(temp);
        return;
    }
    if(temp.back() == '1') fun(n,k,i+1,temp+'0');
    else
    {
        fun(n,k,i+1,temp+'0');
        fun(n,k,i+1,temp+'1');
    }


}
    vector<string> generateValidStrings(int n, int k) {
        fun(n,k,1,"0");
        fun(n,k,1,"1");
        vector<string>res(ans.begin(),ans.end());
        return res;
    }
};