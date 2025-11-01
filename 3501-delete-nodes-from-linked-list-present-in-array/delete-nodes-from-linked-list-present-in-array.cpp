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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp = head;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp2 = dummy;
        while(temp != nullptr)
        {
            if(mp[temp->val] > 0)
            {
                temp = temp->next;
            }
            else
            {
             ListNode* curr = temp;
            temp = temp->next;
            curr -> next = nullptr;
            temp2->next = curr;
            temp2 = temp2->next;
            }
        }
        return dummy->next;
    }
};