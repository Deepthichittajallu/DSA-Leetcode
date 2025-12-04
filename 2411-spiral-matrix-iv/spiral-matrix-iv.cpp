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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>temp(m,vector<int>(n,-1));
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;
        ListNode* temp1 = head;
        while(top <= bottom && left <= right)
        {
            for(int i = left ; i<= right ;i++)
            {
                if(temp1 != nullptr)
                {
                    temp[top][i] = temp1->val;
                    temp1 = temp1->next;
                }
            }
            top++;
            for(int i = top;i<=bottom;i++)
            {
                if(temp1 != nullptr)
                {
                    temp[i][right] = temp1 -> val;
                    temp1 = temp1->next;
                }
            }
            right--;
            if(top > bottom || left > right) break;
            for(int i = right ;i>= left;i--)
            {
                if(temp1 != nullptr)
                {
                    temp[bottom][i] = temp1 -> val;
                    temp1 = temp1->next;
                }
            }
            bottom--;
            for(int i = bottom ; i>=top;i--)
            {
                if(temp1 != nullptr)
                {
                    temp[i][left] = temp1->val;
                    temp1 = temp1->next;
                }
            }
            left++;
        }
        return temp;
    }
};