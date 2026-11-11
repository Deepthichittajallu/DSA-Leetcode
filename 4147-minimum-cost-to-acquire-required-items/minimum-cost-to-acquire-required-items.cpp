class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long a = 1LL*need1 * 1LL*cost1;
        long long b = 1LL*need2 * 1LL*cost2;
        long long c = 1LL*costBoth * 1LL*(max(need1,need2));
       long long maxi = min(need1,need2);
        long long d = 1LL*maxi * 1LL*costBoth;
        long long e = 0;
        if(maxi != need1)
        {
           e =  (need1-maxi) * cost1;
        }
        else
        {
            e = (need2-maxi)* cost2;
        }
        long long ans = min((a+b),c);
        long long ans2 = min(min((a+b),c),(d+e));
        return ans2;
        
    }
};