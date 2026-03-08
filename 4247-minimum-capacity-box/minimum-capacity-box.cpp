class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int mini = INT_MAX;
        int ind = INT_MAX;
        for(int i=0;i<capacity.size();i++)
        {
            if(capacity[i] >= itemSize)
            {
               if(mini > capacity[i])
               {
                    ind = i;
                    mini = capacity[i];
               }
            }
        }
        return (ind == INT_MAX ? -1 : ind);
    }
};