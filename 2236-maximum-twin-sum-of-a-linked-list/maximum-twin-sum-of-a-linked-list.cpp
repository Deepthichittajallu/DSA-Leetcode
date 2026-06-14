/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            // prev = temp;
            temp = temp->next;
            n++;
        }
        ListNode* temp1 = head;
        int maxi = 0 , cnt = 0;
        int half  = (n/2);
        // cout<<half;
        vector<int>arr;
        vector<int>arr1;
        while(cnt < half)
        {
            arr.push_back(temp1->val);
            temp1 = temp1->next;
            cnt++;
        }
        while(temp1 != nullptr)
        {
            arr1.push_back(temp1->val);
            temp1 = temp1->next;
        }
        reverse(arr1.begin(),arr1.end());
        for(int i=0;i<arr.size();i++)
        {
            maxi = max(maxi,arr[i] + arr1[i]);
        }
        return maxi;
    }
};