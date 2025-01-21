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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // brute : traverse through each list and store in an array, then sort the array
        // merge sort 
        // priority queue : minHeap 

        // we are given starting of every linked list 

        // complete -> 
        if(lists.empty()) return NULL; 
        priority_queue<int, vector<int>, greater<int>> min_heap;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy; 

        for(int i=0; i<lists.size(); i++)
        {
            ListNode* temp = lists[i];
            while(temp!=NULL)
            {
                    min_heap.push(temp->val);
                    temp = temp->next;          //the next element
            }
        }

        while(!min_heap.empty())
        {
            curr->next = new ListNode(min_heap.top());
            min_heap.pop();
            curr = curr->next; 
        }

        ListNode *head = dummy->next;
        delete dummy; 
        return head; 
    }




        //method2 : Merge Sort 

    // ListNode* merge(ListNode* l1, ListNode* l2)
    // {
    //     //merge function -> to merge the elements based on their values
    //     // have to merge two lists though 

    //     ListNode* dummy = new ListNode(0);
    //     ListNode* curr = dummy; 

    //     while(l1!=NULL && l2!=NULL)
    //     {
    //         if(l1->val <= l2->val)
    //         {
    //             curr->next = l1; 
    //             l1 = l1->next;
    //         }
    //         else
    //         {
    //             curr->next = l2; 
    //             l2 = l2->next; 
    //         }

    //         curr = curr->next; 
    //     }

    //     curr->next = (l1!=NULL) ? l1 : l2; 

    //     return dummy->next; 
    // }

    // ListNode* MergeSort(vector<ListNode*> arr, int start, int end)
    // {
    //     if(arr.empty()) return NULL; 
    //     if(start == end) return arr[start];
        
    //         int mid = start + (end-start)/2; 

    //         ListNode *left = MergeSort(arr, start, mid);
    //         ListNode *right = MergeSort(arr, mid+1, end);

    //         return merge(left, right);

    // }


    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     if(lists.empty()) return NULL;

    //     return MergeSort(lists, 0, lists.size()-1);
    // }

    

        
};