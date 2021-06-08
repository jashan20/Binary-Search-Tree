
void countN(Node *root, int l, int h, int &count)
{
  // your code goes here   
  if(root == NULL)
  return ;
  countN(root->left,l,h,count);
  if(root->data >= l && root->data <= h)
  count++;
  countN(root->right,l,h,count);
}

//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
  // your code goes here   
  int count;
  countN(root,l,h,count);
  return count;
  
}
