class Solution {
public:
bool res = 1;
void power(int n)
{
    if(n==0)
    {
        res = 0;
        return ;
    }
    if(n==1)
    {
        return;
    } 
    if(n%3 != 0)
    {
        res = 0;
        return ;
    }
    power(n/3);
}
    bool isPowerOfThree(int n) {
        power(n);
        return res;
    }
};