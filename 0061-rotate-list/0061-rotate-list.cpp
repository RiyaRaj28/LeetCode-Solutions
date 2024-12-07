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
    ListNode* findNthNode(ListNode* head, int k)
    {
        int count = 1; 
        ListNode* temp = head; 
        while(temp != NULL)
        { 
            if(count == k) return temp; 

            temp = temp->next; 
            count++; 
        }
        return temp; 
    }

    ListNode* rotateRight(ListNode* head, int k) 
    {
        // reach last node, assign it as tail 
        // tail -> next = head 

        // find new last node by the function 
        // assign the new head by newlastnode -> next 
        // assign newlastnode -> next = null 
        if(head == NULL) return head; 

        ListNode *tail = head, *temp; 
        int n = 1; 
        while(tail->next != NULL)
        {
            tail = tail -> next; 
            n++; 
        }

        if(k % n == 0) return head; 
        k = k % n; 

        tail -> next = head; 
        ListNode *newTail = findNthNode(head, n-k); 

        head = newTail -> next; 
        newTail -> next = NULL; 

        return head; 

        
    }
};