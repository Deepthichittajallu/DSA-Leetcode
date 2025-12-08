class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        // for(int i = 1;i<=n-2;i++)
        // {
        //     int a = i;
        //     int b = i+1;
        //     int c = i+2;
        //     if(a*a + b*b == c*c) cnt++;
        //     if(b*b + a*a == c*c) cnt++;
        // }
        // return cnt;
        for(int i = 1;i<=n;i++){
            for(int j =1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    // cout<<i<<" "<<j<<" "<<k<<endl;
                    if(i*i + j*j == k*k) cnt++;
                }
            }
        }
        return cnt;
    }
};