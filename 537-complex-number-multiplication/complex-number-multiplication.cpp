class Solution {
public:
    int comp(string num1)
    {
        int pos = 0;
        int i =0;
        int num = 0;
        while(num1[i] != '+')
        {
            i++;
            pos = i;
        }
        int temp = 1;
        if(num1[pos+1] == '-') temp = -1;
        // cout<<temp<<" ";
        for(int j = pos+1;j<num1.size()-1;j++)
        {
            if(num1[j] >= '0' && num1[j] <= '9')
            {
                int rem = num1[j] - '0';
                num = (num*10) + rem;
            }
        }
        return num*temp;
    }
    int realnum(string num1)
    {
        int real1 = 0;
        int temp = 1;
        if(num1[0] == '-') temp = -1;
        for(int i =0;i<num1.size();i++)
        {
            if(num1[i] == '+') break;
            else 
            {
                if(num1[i] >= '0' && num1[i] <= '9')
                {
                    int rem = num1[i] - '0';
                    real1 = (real1*10)+rem;
                }
            }
        }
        return real1*temp;
    }
    string complexNumberMultiply(string num1, string num2) {
        int real1 =0,real2 = 0,com1 =0 ,com2 =0;
        real1 = realnum(num1);
        real2 = realnum(num2);
        com1 = comp(num1);
        com2 = comp(num2);
        int a = real1*real2;
        int c = com1*real2;
        int b = real1*com2;
        int d = com2 * com1*(-1);
        int img = c+b;
        int realpart = a+d;
        cout<<realpart<<" "<<img;
        string res = "";
        res+=to_string(realpart);
        res+="+";
        res+=to_string(img);
        res+="i";
        return res;
    }
};