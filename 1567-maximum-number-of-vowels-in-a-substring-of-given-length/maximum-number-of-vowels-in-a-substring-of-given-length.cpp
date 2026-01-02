class Solution {
public:
bool isvowel(char c)
{
    return (c == 'a' || c=='e' || c== 'i' || c == 'o' || c == 'u');
}
    int maxVowels(string s, int k) {
        int maxi =  INT_MIN;
        int cnt = 0;
        for(int i=0;i<k;i++)
        {
            if(isvowel(s[i])) cnt++;
        }
        maxi = max(maxi,cnt);
        int l = 0;
        int r = k;
        while(r < s.size())
        {
            if(isvowel(s[l])) 
            {
                cnt--;
            }
            if(isvowel(s[r])) 
            {
                cnt++;
            }
           l++;
           r++;
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};