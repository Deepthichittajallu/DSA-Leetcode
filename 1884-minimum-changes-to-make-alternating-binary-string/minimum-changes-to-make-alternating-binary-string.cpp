class Solution {
public:
int fun(string s,char ch)
{
    int cnt = 0;
    bool found = false;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == ch && found == false)
        {
            found = true;
           continue;
        }
        else if(s[i] != ch && found == true)
        {
            found = false;
            continue;
        }
        else
        {
           found = !found;
            cnt++;
        } 
    }
    cout<<cnt<<endl;
    return cnt;
}
    int minOperations(string s) {
        int cnt1 = 0;
        int cnt2 = 0;
        cnt1 = fun(s,'0');
        cnt2 = fun(s,'1');
        return min(cnt1,cnt2);
        
    }
};