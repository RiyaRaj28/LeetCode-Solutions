/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //hashing
        map<ListNode*, int> mpp; 
        ListNode *temp = head; 
        while(temp)
        {
            // if(mpp.count(temp)!=0)
            // {
            //     return temp;
            // }

            // mpp[temp] = 1; 
            // temp = temp->next; 

            if(mpp.find(temp) != mpp.end()) return temp; 

            mpp[temp] = 1; 
            temp = temp->next; 
        }
        return NULL; 

        //tortoise-hare
        // ListNode *slow=head, *fast=head;
        // while(fast!=NULL && fast->next!=NULL)
        // {
        //     slow = slow->next; 
        //     fast = fast->next->next;

        //     if(slow==fast)
        //     {
        //         slow = head; 
        //         while(slow!=fast)
        //         {
        //             slow = slow->next;
        //             fast = fast->next; 
        //         }
        //         return slow; 
        //     } 
        // }
        // return NULL; 
    }
};