class Solution {
public:
    vector<string>ans;
    void fun(int m,int n,string str)
    {
        if(m >= n)
        {
            ans.push_back(str);
            return;
        }
        char last = str.back();
        if(last == '0')
        {
            str += '1';
            fun(m+1,n,str);
            str.pop_back();
        }
        if(last == '1')
        {
            str += '1';
            fun(m+1,n,str);
            str.pop_back();
            str += '0';
            fun(m+1,n,str);
            str.pop_back();
        }

    }
    vector<string> validStrings(int n) {
        string str1 = "0";
        fun(1,n,str1);
        str1 = "1";
        fun(1,n,str1);
        return ans;
    }
};