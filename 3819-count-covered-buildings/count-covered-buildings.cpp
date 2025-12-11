class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& bu) {
        sort(bu.begin(),bu.end());
        unordered_map<int,set<int>>mp1,mp2;
        for(int i=0;i<bu.size();i++)
        {
            mp1[bu[i][0]].insert(bu[i][1]);
            mp2[bu[i][1]].insert(bu[i][0]);
        }
        int res = 0;
        // for(auto it:mp)
        // {
        //     cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
        // }
        int cnt = 0;
        for(int i=0;i<bu.size();i++)
        {
            cnt = 0;
            int a = bu[i][0];
            int b = bu[i][1];
            auto it = mp1[a].find(b);
            if(it != mp1[a].begin()) cnt++;
            if(next(it)!= mp1[a].end()) cnt++;
            auto it2 = mp2[b].find(a);
            if(it2 != mp2[b].begin()) cnt++;
            if(next(it2) != mp2[b].end()) cnt++;
            if(cnt == 4) res++;

        }
        return res;
    }
};