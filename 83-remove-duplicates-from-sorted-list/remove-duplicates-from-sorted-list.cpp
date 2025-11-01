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
        ListNode* dummy = new ListNode(-1);
        if(head == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* temp1 = head;
        ListNode* temp2 = dummy;
        ListNode* curr = temp1;
        temp1 = temp1->next;
        temp2 -> next = curr;
        curr -> next = nullptr;
        temp2 = temp2 -> next;

        while(temp1 != nullptr)
        {
            ListNode* tempo = temp1;
            if(tempo->val == curr->val)
            {
                curr = temp1;
                temp1 = temp1->next;
            }
            else
            {
                curr = temp1;
                temp1 = temp1->next;
                temp2 -> next = curr;
                curr -> next = nullptr;
                temp2 = temp2 -> next;
            } 
        } 
        return dummy->next;
    }
};