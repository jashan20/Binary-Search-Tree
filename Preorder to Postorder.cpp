/*Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.

Example 1:

Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
Explanation: PreOrder: 40 30 35 80 100
InOrder: 30 35 40 80 100
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \   
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40
Example 2:

Input:
N = 8
arr[]  = {40,30,32,35,80,90,100,120}
Output: 35 32 30 120 100 90 80 40*/

//User function template in C++

Node* construct(int pre[],unordered_map<int,int> &m,int si,int ei,int &index)
{
    if(si > ei)
    return NULL;
    
    Node *root = newNode(pre[index++]);
    int inindex = m[root->data];
    root->left = construct(pre,m,si,inindex-1,index);
    root->right = construct(pre,m,inindex+1,ei,index);
    return root;
}
//Function that constructs BST from its preorder traversal.
Node* constructTree(int pre[], int n)
{
    //code here
    set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(pre[i]);
    }
    unordered_map<int,int> m;
    int i=0;
    for(int x:s)
    {
        m[x] = i;
        i++;
    }
    int index =0;
    Node *root = construct(pre,m,0,n-1,index);
    return root;
}
