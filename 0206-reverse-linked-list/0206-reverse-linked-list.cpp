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
    // ListNode* reverseList(ListNode* head) 
    // {
    //     if(head == NULL || head->next == NULL) return head; 
    //     ListNode *curr=head, *prev=NULL, *front=NULL; 

    //     while(curr!=NULL)
    //     {
    //         front = curr ->next; 
    //         curr->next = prev;
    //         prev = curr; 
    //         curr = front; 
    //     }
        
    //     return prev; 
    // }

    ListNode* reverse(ListNode* prev, ListNode* curr)
    {
        if(curr == NULL) return prev; 

        ListNode* front = curr->next; 
        curr -> next = prev; 

        return reverse(curr, front); 
    }

    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) return head; 
        ListNode *curr=head, *prev=NULL; 

        // while(curr!=NULL)
        // {
        //     front = curr ->next; 
        //     curr->next = prev;
        //     prev = curr; 
        //     curr = front; 
        // }

        return reverse(prev, curr);
        
        // return prev; 
    }
};