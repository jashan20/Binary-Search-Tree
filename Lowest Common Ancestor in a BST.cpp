//METHOD 1 - VALID FOR BT AND BST
//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(root == NULL)
   return NULL;
   
   if(root->data == n1 || root->data == n2)
   return root;
   Node* lca1 = LCA(root->left,n1,n2);
   Node* lca2 = LCA(root->right,n1,n2);
   if(lca1 != NULL && lca2 != NULL)
   return root;
   if(lca1 != NULL)
   return lca1;
   else
   return lca2;
}

//METHOD 2 ONLY VALID FOR BST
//Function to find the lowest common ancestor in a BST.
Node* LCA(Node *root, int n1, int n2)
{
    // base case
    if(root==NULL)
        return NULL;
    
    //If both n1 and n2 are smaller than data at current node, we call 
    //the function recursively for finding LCA in the left subtree. 
    if(n1<root->data and n2<root->data)
    {
        return LCA(root->left,n1,n2);
    }
    //If both n1 and n2 are greater than data at current node, we call 
    //the function recursively for finding LCA in the right subtree. 
    if(n1>root->data and n2 > root->data)
    {
        return LCA(root->right,n1,n2);
    }
    
    //returning the lowest common ancestor.
    return root;
}
