class Solution {
public:
int fun(string s,int k,char c)
{
    int l = 0;
    int r = 0;
    int temp = k;
    int ans = INT_MIN;
    while(r < s.size())
    {
        if(s[r] != c) temp--;
        while(temp < 0)
        {
            ans = max(ans,r-l);
            if(s[l] != c) temp++;
            l++;
        }
        r++;
    }
     ans = max(ans,r-l);  
    return ans;
}
    int maxConsecutiveAnswers(string s, int k) {
        int a = fun(s,k,'T');
        int b = fun(s,k,'F');
        cout<<a<<" "<<b; 
        return max(a,b);
    }
};