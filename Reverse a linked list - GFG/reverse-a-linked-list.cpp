//{ Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        int a[10001];
        int i=0;
        while(head)
        {
            a[i++]=(head->data);
            head=head->next;
        }
      int j=0,k=i-1;
      while(j<=k)
      {
          int t=a[j];
          a[j]=a[k];
          a[k]=t;
          j++;
          k--;
      }
    //   for(int ii=0;ii<i;ii++)
    //   cout<<a[ii]<<endl;
         struct Node*t=new struct Node(0);
        
         struct Node*kk=t;
        for(int ii=0;ii<i;ii++)
        {
        t->data=a[ii];
         
        if(ii!=i-1)
        {
        t->next=new struct Node(0);
        t=t->next;
        }
        }
        t->next=NULL;
        return kk;
        
    }
    
};
    


//{ Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends