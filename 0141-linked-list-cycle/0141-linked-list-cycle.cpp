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
    bool hasCycle(ListNode *head) {
        // //map method - hashing method
        // // map<ListNode* , int> mpp;
        // // ListNode* temp = head;
        // // while(temp)
        // // {
        // //     if(mpp.find(temp) != mpp.end())
        // //         return true; 
            
        // //     mpp[temp] = 1;
        // //     temp = temp->next; 
        // // }
        // // return false; 

        // //tortoise-hare method 
        // ListNode *fast = head, *slow = head;
        // while(fast != NULL && fast->next!=NULL)
        // {
        //     slow = slow->next;
        //     fast = fast->next->next;
        //     if(slow == fast)
        //     {
        //         return true; 
        //     }
        // }
        // return false; 

















        //storing in hashmap 
        // map<ListNode*, int> mpp; 

        //traverse through the entire ll and insert elements into the hashmap with a value of 1
        //if before inserting a value in the hashmap it is already found, then return true

        // ListNode* temp = head; 
        // while(temp!=NULL)
        // {
        //     if(mpp.find(temp) != mpp.end()) return true; 

        //     mpp[temp] = temp->val; 

        //     temp = temp->next; 
        // }

        // return false; 

        //tortoise hare method 

        ListNode* slow = head, *fast = head; 
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next; 
            fast = fast->next->next; 

            if(fast == slow) return true; 
        }

        return false; 
    }
};