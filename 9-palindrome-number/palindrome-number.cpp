class Solution {
public:
    bool isPalindrome(int x) {
        long long num = 0;
        long long temp = x;
        if(temp<0) return false;
        while(x!=0)
        {
            long long rem = x%10;
            num = num*10+rem;
            x/=10;
        }
        if(num == temp) return true;
        return false;
    }
};