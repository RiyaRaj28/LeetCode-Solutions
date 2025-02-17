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

    ListNode* reverseLL(ListNode *head)
    {
        ListNode *prev = NULL, *curr=head; 
        if(head==NULL || head->next == NULL) return head; 
        while(curr != NULL)
        {
            ListNode *front = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = front; 
        }
        return prev; 


    }

    ListNode* reverse(ListNode* head)
{
	ListNode* prev = NULL; 
	ListNode* curr = head; 

	while(curr != NULL)
	{
		ListNode* front = curr -> next; 
		curr -> next = prev; 
		
		prev = curr; 
		curr = front; 
	} 

	return prev; 
} 


    bool isPalindrome(ListNode* head) {
        //brute : stack ds
        // stack <int> st;
        // ListNode* temp = head; 
        // while(temp)
        // {
        //     st.emplace(temp->val);
        //     temp = temp->next; 
        // }
        // temp = head; 
        // while(temp!= NULL && (temp->next)!= NULL)
        // {
        //     if((temp->val) != st.top()) return false; 
        //     temp = temp->next; 
        //     st.pop(); 
        // }
        // return true; 

        //optimal : reverse half list and check in one traversal 
        // ListNode *slow = head, *fast= head;
        // //we want the first mid elem so we stop fast at 2nd last in case of even num of elem thus  fast=fast->next
        
        // if(head==NULL || head->next == NULL) return true; 
        // while(fast->next!=NULL && fast->next->next!=NULL)
        // {
        //     slow = slow->next; 
        //     fast = fast->next->next; 
        // }

        // //slow is at first mid
        // ListNode* newHead = reverseLL(slow->next); 
        // ListNode *first=head, *second = newHead, *evenHead = newHead; 

        // while(second!=NULL)
        // {
        //     if((first->val) != (second->val)) 
        //     { 
        //         reverseLL(evenHead);
        //         return false; 
        //     }
        //     first = first->next; 
        //     second = second->next; 
        // }
        
        // reverseLL(evenHead);
        // return true; 








    // ListNode* slow = head; 
	// ListNode* fast = head;

	// while(fast != NULL && fast -> next != NULL) 
	// {
	// 	slow = slow -> next; 	
	// 	fast = fast -> next -> next; 
	// } 

	// // slow is at middle of the linkedList 
	// ListNode* newHead = reverse(slow->next); 




	// // slow->next = NULL; 

	// ListNode* first = head; 
	// ListNode* second = newHead; 

	// while(second != NULL)
	// {
	// 	if(first -> val != second -> val) return false; 
	// 	first = first -> next; 
	// 	second = second -> next; 
	// } 

	// return true; 

    stack<int>st; 
    ListNode* fast = head; 
    ListNode* slow = head; 

while(fast != NULL && fast -> next != NULL)
{
	fast = fast -> next -> next; 
	slow = slow -> next; 
}



while(slow != NULL)
{
	st.push(slow->val); 
	slow = slow -> next; 
}





ListNode* temp = head; 
while(!st.empty())
{
	if(st.top() != temp -> val)
{
 	return false; 

}	
	
	st.pop(); 
temp = temp-> next;
	
}

return true; 


    }
};