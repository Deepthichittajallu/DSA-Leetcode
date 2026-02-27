class Solution {
public:
set<string>res;
void solve(int n,int open,int close,string &temp)
{
    if(open==close &&open ==n)
    {
        res.insert(temp);
        return;
    }
    if(open <= n) 
    {
        temp += '(';
        solve(n,open+1,close,temp);
        temp.pop_back();
    }
    if(open > close)
    {
        temp += ')';
        solve(n,open,close+1,temp);
        temp.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
       string temp = "(";
        int open = 1;
        int close = 0;
        solve(n,open,close,temp);
        vector<string>ans(res.begin(),res.end());
        return ans;
    }
};