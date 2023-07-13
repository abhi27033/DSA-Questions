//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct Node* deleteNode(struct Node* root, int key);

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        root1 = deleteNode(root1, k);
        vector<int> v;
        inorder(root1, v);
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

Node* minnode(Node*r)
{
    if(r->left==NULL)
    return r;
    return minnode(r->left);
}
void solve(Node *r, int x, Node *p) {
    if (r == NULL)
        return;
    
    if (r->data == x) {
        if (r->left && r->right) {
            // Both children are present
            Node *m = minnode(r->right);
            r->data = m->data;
            solve(r->right, m->data, r);
        } else {
            Node *temp = r;
            
            // Update parent's child pointer
            if (p == NULL) {
                // Deleting root node
                if (r->left)
                    r = r->left;
                else
                    r = r->right;
            } else if (p->left == r) {
                // r is the left child of parent p
                if (r->left)
                    p->left = r->left;
                else
                    p->left = r->right;
            } else {
                // r is the right child of parent p
                if (r->left)
                    p->right = r->left;
                else
                    p->right = r->right;
            }
            
            delete temp;
        }
    } else if (r->data < x) {
        solve(r->right, x, r);
    } else {
        solve(r->left, x, r);
    }
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(root->data==X&&!root->left&&!root->right)
    return NULL;
    solve(root,X,NULL);
    return root;
    
    
}
