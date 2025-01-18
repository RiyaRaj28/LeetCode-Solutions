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

class Compare{
    public : 
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val; 
    }
};

class Solution {
public:
    // bool compar(ListNode* a, ListNode* b)
    // {
    //     return a->val < b->val; 
    // }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*, vector<ListNode*>, Compare >pq; 
        int count = 0; 

        for(int i=0; i<lists.size(); i++)
        {
            // ListNode head = lists[i][0];
            ListNode* temp = lists[i]; 
            while(temp != NULL)
            {
                count++;
                pq.push(temp);
                temp = temp->next; 
            }
        }

        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead; 
       
        while(count--)
        {
            // ListNode* newNode = pq.top();
            // pq.pop();

            temp->next = pq.top();
            pq.pop(); 
            temp = temp->next; 
        }

        temp->next = NULL; 
        return dummyHead->next; 
    }
};