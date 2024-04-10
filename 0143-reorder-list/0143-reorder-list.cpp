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
    ListNode* reorderLis(ListNode* head) {
     if(!head||!head->next||!head->next->next)
            return head;
        ListNode* prev=NULL,*t=head;
        while(t->next)
        {
            prev=t;
            t=t->next;
        }
        ListNode* ans=head;
        ListNode* fir=head->next;
        ans->next=t;
        prev->next=NULL;
        t->next=reorderLis(fir);
        return ans;
    }
    void reorderList(ListNode* head) {
       head=reorderLis(head);
    }
};