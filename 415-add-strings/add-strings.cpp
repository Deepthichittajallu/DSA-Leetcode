class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int m = num1.size();
        int n = num2.size();
        int i=0,j=0,carry =0;
        string res = "";
        while(i<m||j<n||carry == 1)
        {
            int sum = 0;
            if(i<m) sum += num1[i++]-'0';
            if(j<n) sum += num2[j++] - '0';
            sum += carry;
            carry = sum/10;
            res += to_string(sum%10);
        }
        if(carry > 0) res += to_string(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};