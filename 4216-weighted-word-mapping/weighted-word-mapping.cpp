class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
       string res;
        map<int,char>mp;
        mp[25] = 'a';
        mp[24] = 'b';
        mp[23] = 'c';
        mp[22] = 'd';
        mp[21]  = 'e';
        mp[20] = 'f';
        mp[19] = 'g';
        mp[18] = 'h';
        mp[17] = 'i';
        mp[16] = 'j';
        mp[15] = 'k';
        mp[14] = 'l';
        mp[13] = 'm';
        mp[12] = 'n';
        mp[11] = 'o';
        mp[10] = 'p';
        mp[9] = 'q';
        mp[8] = 'r';
        mp[7] = 's';
        mp[6] = 't';
        mp[5] = 'u';
        mp[4] = 'v';
        mp[3] = 'w';
        mp[2] = 'x';
        mp[1] = 'y';
        mp[0] = 'z';
        for(int i=0;i<words.size();i++)
            {
                int temp = 0;
                for(int j=0;j<words[i].size();j++)
                    {
                        int a = words[i][j];
                        int b = a - 97;
                        temp += weights[b];
                    }
                temp = temp%26;
                res += mp[temp];
            }
        return res;
    }
};