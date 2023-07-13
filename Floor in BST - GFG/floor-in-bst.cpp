//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

int floor(Node *root, int x);

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << floor(root, s) << "\n";
    }
}

// } Driver Code Ends


// Function to search a node in BST.
void solve(vector<int>&v,Node* r)
{
    if(!r)
    return;
    solve(v,r->left);
    v.push_back(r->data);
    solve(v,r->right);
}
int floor(Node* root, int x) {
    // Code here
    int input=x;
    if (root == NULL) return -1;
    vector<int> v;
    solve(v,root);
    // for(auto it:v)
    // cout<<it<<endl;
    int ans=lower_bound(v.begin(),v.end(),input)-v.begin();
    // cout<<ans;
    if(ans==v.size())
    return v[v.size()-1];
    if(v[0]>input)
    return -1;
   
    if(ans>0&&v[ans-1]<=input&&v[ans]>input)
    return v[ans-1];
    return v[ans];
}
