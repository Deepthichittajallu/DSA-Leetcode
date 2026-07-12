class Solution {
public:
    int minimumCost(vector<int>& arr, int k) {
        const int mod = 1e9+7;
        long long cost = 0;
        long long ans = 0;
        long long temp = k;
        for(long long i=0;i<arr.size();i++)
        {
            if(arr[i] <= k)
            {
                k -= arr[i];
            }
            else
            {
                arr[i] -= k;
                long long tempo = arr[i]%mod / temp%mod;
                if(arr[i]%temp != 0) tempo += 1;
                // cout<<tempo<<" ";
                cost += (tempo%mod);
                k = (tempo * temp - arr[i]);
            }
        }
        ans = (1LL*(cost%mod) *( (cost+1)%mod)/2)%mod;
        return (int)ans;
    }
};