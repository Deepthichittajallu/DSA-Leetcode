class Solution {
public:
string add(string &temp1,string temp2)
{
    reverse(temp1.begin(),temp1.end());
    int carry = 1;
    string res = "";
    for(int i=0;i<temp1.size();i++)
    {
        if(temp1[i] == '1' && carry == 1)
        {
            res += '0';
            carry = 1;
        }
        else if((carry == 1 && temp1[i] == '0') || (carry == 0 && temp1[i] == '1'))
        {
            res += '1';
            carry = 0;
        }
        else
        {
            res += '0';
            carry = 0;
        }
    }
    if(carry == 1) res += '1';
    reverse(res.begin(),res.end());
    return res;

}
    int numSteps(string s) {
        int cnt = 0;
        while(s.size() > 1)
        {
            int n = s.size();
            if(s[n-1] == '1')
            {
                cnt++;
                s = add(s,"1");
            }
            else
            {
                cnt++;
                s.pop_back();
            }
        }
        return cnt;
    }
};