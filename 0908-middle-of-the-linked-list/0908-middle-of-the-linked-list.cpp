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
    ListNode* middleNode(ListNode* head) 
    {
        //BRUTE 
        ListNode *temp = head;
        int count = 0; 
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }

        int mid_count = (count/2) + 1;

        temp = head;
        // while(temp!=NULL)
        // {
        //     mid_count -= 1;
        //     if(mid_count == 0)
        //     {
        //         break;
        //     }
        //     temp = temp-> next; 
        // }

        while(mid_count > 1)
        {
            // mid_count -= 1;
            // if(mid_count == 0)
            // {
            //     break;
            // }
            
            temp = temp->next; 
            mid_count -= 1; 
        }

        return temp; 

        //TORTOISE - HARE

        // ListNode *fast = head, *slow = head;
        // while(fast!=NULL && fast->next != NULL)
        // {
        //     slow = slow->next;
        //     fast = fast->next->next; 
        // }
        // return slow; 

    }
};