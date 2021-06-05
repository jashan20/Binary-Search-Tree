//using fact that BST INORDER TRAVERSAL IS ALWAYS SORTED
void print(vector<int> &v,Node* root,int low, int high)
{
    if(root != NULL)
    {
        print(v,root->left,low,high);
        if(root->data >= low && root->data <= high)
        v.push_back(root->data);
        print(v,root->right,low,high);
    }
}

//Function to return a list of BST elements in a given range.
vector<int> printNearNodes(Node *root, int low, int high)
{
  // your code goes here 
  vector<int> v;
  print(v,root,low,high);
  return v;
  
}
