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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {

        // initialise a new head and a new tail as nulls 
        // take curr till the very last 

        // take cnt = 0 
        // reverse in groups of k, prev, next etc 
        ListNode* newHead = NULL; 
        ListNode* tail = NULL;
        ListNode* curr = head; 

        while(curr!=NULL)
        {
            int checkcnt = 0; 
            ListNode* check = curr; 
            while(check && checkcnt < k)
            {
                checkcnt++; 
                check = check->next; 
            }

            // If less than k nodes left, attach as is and break
            if(checkcnt < k)
            {
                if(tail) tail->next = curr;
                else newHead = curr;
                break;
            }


            ListNode* groupHead = curr; 
            // ListNode* temp = curr; 

            int cnt = 0; 
            ListNode* prev = NULL;
            while(curr && cnt<k)
            {
                ListNode* front = curr->next; 
                curr->next = prev; 
                prev = curr; 
                curr = front;
                cnt++; 
            }

            if(newHead == NULL)
            {
                newHead = prev;
            }

            if(tail != NULL)
            {
                tail -> next = prev;
            }
            tail = groupHead;
            // curr = temp; 
        }
        return newHead;
    }
};