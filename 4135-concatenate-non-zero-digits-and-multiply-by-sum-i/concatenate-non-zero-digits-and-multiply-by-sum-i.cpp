class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string str = to_string(n);
        string str1 = "";
        int ans = 0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i] != '0')
            {
                str1 += str[i];
                ans += str[i] - '0';
            }
        }
        int temp = stoi(str1);
        return 1LL*temp*ans;
    }
};