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

 // kal se, ye timer 5 baje start hona chahiye aur raat 9 baje end hona chahiye. 
class Solution {
public:
    void reorderList(ListNode* head) 
    {
        ListNode* curr = head; 

        while(curr && curr->next)
        {
            ListNode* temp = curr->next; 
            while(temp->next && temp->next->next!=NULL)
            {
                temp = temp->next; 
            }

            ListNode* tolink = temp->next; 
            if(!tolink) break; 

            temp->next = NULL; 

            tolink->next = curr->next; 
            curr->next = tolink; 

            curr = tolink->next; 
        }

        // return head; 

        
    }
};