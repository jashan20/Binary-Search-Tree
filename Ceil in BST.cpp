//Given a BST and a number X, find Ceil of X.
//Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

//Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) 
{ 
    if (root == NULL) 
        return -1; 
  
    // Your code here
    int res = -1;
    while(root != NULL)
    {
        if(root->data == input)
        return input;
        else if(root->data < input)
        root = root->right;
        else
        {
            res = root->data;
            root = root->left;
        }
    }
    return res;
    
} 
