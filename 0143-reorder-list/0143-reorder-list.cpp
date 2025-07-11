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

    ListNode* reverse(ListNode* node)
    {
        if(!node) return node; 

        ListNode* prev = NULL; 

        while(node)
        {
            ListNode* front = node->next; 
            node->next = prev; 
            

            prev = node; 
            node = front; 
        }
        return prev;
    }

    void reorderList(ListNode* head) 
    {
        // ListNode* curr = head; 

        // while(curr && curr->next)
        // {
        //     ListNode* temp = curr->next; 
        //     while(temp->next && temp->next->next!=NULL)
        //     {
        //         temp = temp->next; 
        //     }

        //     ListNode* tolink = temp->next; 
        //     if(!tolink) break; 

        //     temp->next = NULL; 

        //     tolink->next = curr->next; 
        //     curr->next = tolink; 

        //     curr = tolink->next; 
        // }

        // return head; 

        ListNode* temp = head; 

        ListNode* slow = head, *fast = head; 
        while(fast && fast->next)
        {
            slow = slow->next; 
            fast = fast->next->next; 
        }

        ListNode* mid = slow->next; 
        slow->next = NULL; 
        ListNode* reversedhead = reverse(mid); 

        

        ListNode* left = head->next, *right = reversedhead; 

        while(left && right)
        {
            
            temp->next = right; 
            right = right->next; 
            temp = temp->next; 

            temp->next = left; 
            left = left->next; 
            temp=temp->next;

        }

        if(left) temp->next = left;
        if(right) temp->next = right;

        // return dummy->next;
    }
};