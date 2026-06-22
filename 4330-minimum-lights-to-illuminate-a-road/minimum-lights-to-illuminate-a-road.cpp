class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int>pre(n+1,0);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(lights[i] > 0)
            {
                int a = max(0,i-lights[i]);
                int b = min(n-1,i+lights[i]);
                pre[a] += 1;
                pre[b+1] -= 1;
            }
        }
        int cnt= 0;
        for(int i=1;i<n;i++)
        {
            pre[i] = pre[i-1] + pre[i];
        }
        for(int i=0;i<n;i++)
        {
            if(pre[i] <= 0)
            {
                cnt++;
            }
            else
            {
                ans += ((cnt%3 == 0) ? cnt/3 : cnt/3 + 1);
                cnt = 0;
            }
        }
        
        if(cnt != 0)
        {
            if(cnt%3 != 0 ) ans += cnt/3 + 1;
            else ans += cnt/3;
        }
        return ans;
    }
};