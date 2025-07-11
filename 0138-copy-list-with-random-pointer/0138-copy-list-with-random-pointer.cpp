/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node* temp = head; 
        if(head == NULL) return head; 

        while(temp)
        {
            Node* clone = new Node(temp->val); 
            clone->next = temp->next; 
            temp->next = clone; 
            temp = temp->next->next; 
        }

        Node* cloneHead = head->next; 
        Node* clone = cloneHead; 
        temp = head; 

        while(temp)
        {
            if(temp->random)
            {
                temp->next->random = temp->random->next; 
                
            }
            temp = temp->next->next;
        }

        temp = head;

        while(clone->next)
        {
            temp->next = temp->next->next; 
            clone->next = clone->next->next; 

            temp = temp->next; 
            clone = clone->next; 
        }

        temp->next = NULL; 
        clone->next = NULL; 

        return cloneHead; 
    }
};