//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        struct Node*n=head;
        int c=0;
        while(n)
        {
            c++;
            n=n->next;
        }
         vector<int> f,b,ans;
        if(c%2==0)
        {
        int t=0;
        n=head;
        while(n)
        {
            if(t<c/2)
           f.push_back(n->data);
           else
           b.push_back(n->data);
           t++;
           n=n->next;
        }
        reverse(b.begin(),b.end());
        for(int i=0;i<f.size();i++)
        {
            ans.push_back(b[i]-f[i]);
        }
        reverse(f.begin(),f.end());
        for(auto it:f)
        ans.push_back(it);
        }
        else
        {
        int t=0;
        n=head;
        int q=0;
        while(n)
        {
           if(t<c/2)
           f.push_back(n->data);
           else if(t>c/2)
           b.push_back(n->data);
           else
           q=n->data;
           t++;
           n=n->next;
        }
        reverse(b.begin(),b.end());
        for(int i=0;i<f.size();i++)
        {
            ans.push_back(b[i]-f[i]);
        }
        reverse(f.begin(),f.end());
        ans.push_back(q);
        for(auto it:f)
        ans.push_back(it);
        }
        n=head;
        int i=0;
        while(n)
        {
            n->data=ans[i++];
            n=n->next;
        }
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends