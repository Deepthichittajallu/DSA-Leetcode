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
        if(last == 'a')
        {
            str += 'b';
            fun(m+1,n,str);
            str.pop_back();
            str += 'c';
            fun(m+1,n,str);
            str.pop_back();
        }
        if(last == 'b')
        {
            str += 'a';
            fun(m+1,n,str);
            str.pop_back();
            str += 'c';
            fun(m+1,n,str);
            str.pop_back();
        }
        if(last == 'c')
        {
            str += 'a';
            fun(m+1,n,str);
            str.pop_back();
            str += 'b';
            fun(m+1,n,str);
            str.pop_back();
        }


    }
    string getHappyString(int n, int k) {
        string str = "a";
        fun(1,n,str);
        str = "b";
        fun(1,n,str);
        str = "c";
        fun(1,n,str);
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        if(k-1 >= ans.size() || k-1 < 0) return "";
        return ans[k-1];
    }
};