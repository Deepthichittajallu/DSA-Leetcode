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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        map<int,int>mp;
        ListNode* temp = head;
        while(temp !=  nullptr)
        {
            mp[temp->val]++;
            temp = temp->next;
        } 
        ListNode* dummy = new ListNode(-1);
        ListNode* temp2 = dummy; 
        ListNode* temp1 = head;
        while(temp1 != nullptr)
        {
            if(mp[temp1->val] == 1)
            {
                ListNode* curr = temp1;
                temp1 = temp1->next;
                temp2->next = curr;
                curr -> next = nullptr;
                temp2 = temp2->next;
            }
            else
            {
            temp1 = temp1 -> next;
            }
        }
        return dummy->next;
    }
};