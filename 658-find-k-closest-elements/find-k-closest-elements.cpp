class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lb = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        if(x > arr[arr.size()-1])
        {
            vector<int>temp;
            for(int i=arr.size()-k;i<arr.size();i++)
            {
                temp.push_back(arr[i]);
            }
            return temp;
        }
        if(x < arr[0])
        {
             vector<int>temp;
            for(int i=0;i<k;i++)
            {
                temp.push_back(arr[i]);
            }
            return temp;
        }
        int i=0,j=0;
        if(arr[lb] != x)
        {
            i = lb - 1;
            j = lb;
        }
        else
        {
            i = lb;
            j=lb+1;
        }
        vector<int>res;
        while(i>=0 && j< arr.size() && res.size() < k)
        {
            if(abs(x-arr[j]) < abs(x-arr[i]))
            {
                res.push_back(arr[j]);
                j++;
            }
            else
            {
                res.push_back(arr[i]);
                i--;
            }
        }
        while(i>=0 && res.size() < k)
        {
            res.push_back(arr[i--]);
        }
        while(j<arr.size() && res.size() < k)
        {
            res.push_back(arr[j++]);
        }
        sort(res.begin(),res.end());
        return res;
    }
};