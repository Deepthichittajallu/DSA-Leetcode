class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k >= arr.size()) return *max_element(arr.begin(),arr.end());
        int maxi = arr[0];
        int l = 1;
        map<int,int>mp;
        while(l<arr.size())
        {
            if(arr[l] >= maxi)
            {
                maxi = arr[l];
                mp[arr[l]]++;
                if(mp[arr[l]] == k) return arr[l];
            }
            else
            {
                mp[maxi]++;
                if(mp[maxi] == k) return maxi;
            }
            l++;
        }
        int ans = 0;
        for(auto it:mp)
        {
            ans = it.first;
        }
        return ans;
    }
};