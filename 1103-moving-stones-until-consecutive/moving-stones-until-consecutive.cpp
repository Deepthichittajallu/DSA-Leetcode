class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int>v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end());
        int dif1 = v[1] - v[0] - 1;
        int dif2 = v[2] - v[1] - 1;
        cout<<dif1<<" "<<dif2;
        if(dif1 == 0 && dif2 == 0) return {0,0};
        else if(dif1 == 0 || dif2 == 0) return {1,max(dif1,dif2)};
        else if(dif1 > 1 && dif2 > 1) return {2,dif1+dif2};
        return {min(dif1,dif2),dif1+dif2};
    }
};