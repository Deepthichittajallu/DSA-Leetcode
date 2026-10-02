class Solution {
public:
vector<string>res;
void fun(int open,int close,string temp)
{
    if(close == 0 && open == 0)
    {
        res.push_back(temp);
        return;
    }
    if(open > 0) fun(open-1,close,temp+'(');
    if(close > open) fun(open,close-1,temp+')');
}
    vector<string> generateParenthesis(int n) {
        string temp = "(";
        int open = n;
        int close = n;
        fun(open-1,close,temp);
        return res;
    }
};