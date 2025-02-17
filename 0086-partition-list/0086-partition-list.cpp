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
    ListNode* partition(ListNode* head, int x) 
    {
    ListNode* beforeEnd = NULL; 
	ListNode* beforeStart = NULL; 
	ListNode* afterEnd = NULL; 
	ListNode* afterStart = NULL;

	ListNode* temp = head; 
	while(temp != NULL)
    {
      ListNode* newNode = new ListNode(temp->val); 

		if(temp -> val < x)
        {
        if(beforeStart == NULL)
            beforeStart = newNode; 		
		else
			beforeEnd -> next = newNode; 

			beforeEnd = newNode;
		}
		else 
		{
			if(afterStart == NULL)
					afterStart = newNode; 
			else
				afterEnd -> next = newNode; 

			afterEnd = newNode; 
		}
		temp = temp->next; 
	} 

if(beforeStart == NULL) return afterStart; 

beforeEnd -> next = afterStart; 

return beforeStart; 


        
    }
};