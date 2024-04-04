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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans=new ListNode(-1);
        ListNode* fin=ans;
        while(1)
        {
            //find min node;
            int an=INT_MAX,idx=-1;
            for(int i=0;i<lists.size();i++)
            {
                ListNode* it=lists[i];
                if(it&&(it->val<an))
                {
                    an=it->val;
                    idx=i;
                }
            }
            // cout<<idx<<endl;
            if(idx==-1)break;
            ans->next=lists[idx];
            ans=ans->next;
            lists[idx]=lists[idx]->next;
        }
        return fin->next;
    }
};