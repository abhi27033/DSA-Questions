//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector <int> &v)
{
    sort( v.begin() , v.end() );
    for( int i=0 ; i<v.size() ; i++ )
        cout<< v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root)
{
    vector <int> v;
    queue <Node*> q;
    
    q.push(root);
    
    Node* next_row = NULL;
    
    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();
        
        if(n==next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }
        
        v.push_back(n->data);
        
        if(n->left)
        {
            q.push(n->left);
            if(next_row == NULL) next_row = n->left;
        }
        
        if(n->right)
        {
            q.push(n->right);
            if(next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/


// } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

Node* solve(int v, unordered_map<int,vector<int>>&m)
{
     Node* a=new Node(v);
     Node* b=a;
     queue<Node*> q;
     q.push(a);
     while(!q.empty())
     {
         int s=q.size();
         while(s--)
         {
             Node* vv=q.front();
             q.pop();
             if(m[vv->data].size()==0)
             {
             vv->left=NULL;
             vv->right=NULL;
             }
             else if(m[vv->data].size()==1)
             {
                 vv->left=new Node(m[vv->data][0]);
                 vv->right=NULL;
             }
             else if(m[vv->data].size()==2)
             {
                 vv->left=new Node(m[vv->data][0]);
                 vv->right=new Node(m[vv->data][1]);
             }
             
             if(vv->left)
             q.push(vv->left);
             if(vv->right)
             q.push(vv->right);
     }
     }
     return b;
}
class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N)
    {
        // Your code here
        unordered_map<int,vector<int>> mp;
        int root=0;
        for(int i=0;i<N;i++)
        {
            if(parent[i]==-1)
            root=i;
            else
            {
                mp[parent[i]].push_back(i);
            }
        }
        return solve(root,mp);
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for( int i=0 ; i<n ; i++ )
            cin>> a[i];
            
        Solution ob;
        
        Node *res = ob.createTree(a,n);
        
        printLevelOrder(res);
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends