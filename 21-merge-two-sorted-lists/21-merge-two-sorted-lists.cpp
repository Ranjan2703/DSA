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
    ListNode* mergeTwoLists(ListNode* curr1, ListNode* curr2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        
        // ListNode* curr1= list1;
        // ListNode* curr2= list2;
        
        while(curr1 and curr2)
        {
            if(curr1->val < curr2->val)
            {
                ptr->next = new ListNode(curr1->val);
                ptr= ptr->next;
                curr1= curr1->next;
                
            }
//            else if(curr1->val < curr2->val)
//             {
//                 ptr->next = new ListNode(curr2->val);
//                 ptr= ptr->next;
//                 curr2= curr2->next;
                
//             }
            else
            {
                ptr->next = new ListNode(curr2->val);
                ptr= ptr->next;
                curr2= curr2->next; 
            }
        }
        while(curr1)
        {
           ptr->next = new ListNode(curr1->val);
                ptr= ptr->next;
                curr1= curr1->next; 
        }
        while(curr2)
        {
              ptr->next = new ListNode(curr2->val);
                ptr= ptr->next;
                curr2= curr2->next;
        }
        return dummy->next;
    }
};