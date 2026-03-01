class Solution {
public:
    int minCost(int n) {
       vector<int>vec(n+1);
       vec[0] = 0;
       vec[1] = 0;
       for(int i=2;i<=n;i++)
       {
        vec[i] = vec[i-1] + (i-1);
       } 
       return vec[n];
    }
};