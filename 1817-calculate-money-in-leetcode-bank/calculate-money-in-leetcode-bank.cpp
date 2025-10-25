class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            int rem = i%7;
            int mod = i/7;
            if(rem == 0)
            {
                sum += (6 + mod);
            }
            else
            {
                sum += (rem+mod);
            }
            cout<<sum<<" ";
        }
        return sum;
    }
};