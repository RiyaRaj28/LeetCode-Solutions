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
    ListNode* deleteMiddle(ListNode* head) 
    {
        int cnt = 0; 
        ListNode* temp = head; 
        if(head == NULL || head->next == NULL) return NULL; 

        while(temp != NULL)
        {
            cnt++;
            temp = temp->next; 
            
        }

        temp = head; 
        cnt = cnt/2; 

        while(temp!= NULL)
        {
            cnt--; 
            if(cnt == 0) break; 
            temp = temp->next;
        }

        ListNode* todel = temp->next; 
        temp->next = temp->next->next; 
        delete(todel); 

        return head; 
        
    }
};