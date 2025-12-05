class Solution {
public:
    string add(string s1,string s2)
    {
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int m = s1.size();
        int n = s2.size();
        int i=0,j=0;
        int carry = 0;
        string res = "";
        while(i<m || j<n || carry == 1)
        {
            int sum = 0;
            if(i<m) sum += (s1[i++] - '0');
            if(j<n) sum += (s2[j++] - '0');
            sum += carry;
            carry = sum/10;
            res+=to_string(sum%10);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string mul(string s,char c,int pos)
    {
        int n = s.size();
        int temp1;
        string tempo;
        int carry = 0;
        int i = s.size()-1;
        while(i>=0)
        {
            temp1 = (s[i] - '0') * (c - '0') + carry;
            carry = temp1/10;
            temp1 = temp1%10;
            tempo+=to_string(temp1);
            i--;
        }
        if(carry > 0)
        {
            tempo += to_string(carry);
        }
        reverse(tempo.begin(),tempo.end());
        while(pos !=0)
        {
            tempo+='0';
            pos--;
        }
        return tempo;
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        reverse(num2.begin(),num2.end());
        vector<string>v;
        int i=0;
        while(i<num2.size())
        {
            string res = mul(num1,num2[i],i);
            v.push_back(res);
            i++;
        }
        string res = "0";
        for(int i=0;i<v.size();i++)
        {
            // cout<<res<<" "<<v[i]<<endl;
            // cout<<v[i]<<" "<<res<<endl;
            // res = add("6888","49200");
            res = add(res,v[i]);

            // break;
        }
        return res;
    }
};