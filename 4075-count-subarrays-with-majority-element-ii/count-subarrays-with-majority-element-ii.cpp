#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class Solution {
public:
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,
tree_order_statistics_node_update>pbds;
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        pbds os;
        os.insert({0,-1});
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == target) nums[i] = 1;
            else nums[i] = -1;
        }
        int pre = 0;
        long long ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            pre += nums[i];
            ans += os.order_of_key({pre,-1});
            os.insert({pre,i});
        }
        return ans;
    }
};