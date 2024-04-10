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
    void reorderList(ListNode* head) {
        if(!head->next)return;
      ListNode* slow=head,*fast=head,*pre=NULL;
        while(fast&&fast->next)
        {
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(pre)pre->next=NULL;
        ListNode* prev=NULL,*curr=slow;
        while(slow)
        {
            ListNode* t=slow->next;
            slow->next=prev;
            prev=slow;
            slow=t;
        }
        //now merge prev and head
        ListNode* ans=new ListNode(-1);
        int flg=1;
        while(prev&&head)
        {
            if(flg)
            {
                ans->next=head;
                ans=ans->next;
                head=head->next;
                flg=0;
            }
            else
            {
                ans->next=prev;
                ans=ans->next;
                prev=prev->next;
                flg=1;
            }
        }
        while(prev)
        {
            ans->next=prev;
            ans=ans->next;
            prev=prev->next;
        }
        while(head)
        {
            ans->next=head;
            ans=ans->next;
            head=head->next;
        }
        
    }
};