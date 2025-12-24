class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(auto it:apple)
        {
            sum += it;
        }
        sort(capacity.begin(),capacity.end());
        int m = capacity.size();
        int temp = 0;
        for(int i = m-1;i>=0;i--)
        {
            temp += capacity[i];
            if(temp>=sum) return m-i;
        }
        return 0;
    }
};