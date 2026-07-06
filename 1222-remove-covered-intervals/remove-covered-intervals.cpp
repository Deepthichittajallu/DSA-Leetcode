class Solution {
public:
// bool compare(const vector<int>&a,const vector<int>&b)
// {
//     return a[1] > b[1];
// }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        stack<pair<int,int>>st;

        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        st.push({intervals[0][0] , intervals[0][1]});
        for(int i=1;i<intervals.size();i++)
        {
            int a = st.top().first;
            int b = st.top().second;
            int c = intervals[i][0];
            int d = intervals[i][1];
            if(b >= c && b >= d)
            {
                if(b >= d)
                {
                    st.pop();
                    st.push({a,b});
                }
                else{
                    st.pop();
                    st.push({a,d});
                }
            }
            else{
                st.push({c,d});
            }
        }
        return st.size();
    }
};