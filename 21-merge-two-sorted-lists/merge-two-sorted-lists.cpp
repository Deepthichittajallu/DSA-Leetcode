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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummy = new ListNode(-1);
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        ListNode* demo = dummy;
        while(temp1 != nullptr && temp2 != nullptr)
        {
            if(temp1->val <= temp2 -> val)
            {
                demo->next = temp1;
                temp1 = temp1->next;
                demo = demo->next;
            }
            else
            {
                demo->next = temp2;
                temp2 = temp2->next;
                demo = demo->next;
            }
        }
        if(temp1) demo->next = temp1;
        if(temp2) demo->next = temp2;
        return dummy->next;
    }
};