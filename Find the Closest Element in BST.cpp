/*Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.

Example 1:

Input:
        10
      /   \
     2    11
   /  \ 
  1    5
      /  \
     3    6
      \
       4
K = 13
Output: 2
Explanation: K=13. The node that has
value nearest to K is 11. so the answer
is 2 */

int minDiff(Node *root, int k)
    {
        if(!root)
            return INT_MAX;
        
        //if given value is present in BST then least difference would be 0.
        if( root->data == k )
            return 0;
            
        //if data at current node is more than given value, we try to find 
        //the answer by calling function recursively for left subtree.
        if( root->data > k )
            return min( abs(root->data-k) , minDiff(root->left, k) );
        
        //else we call the function recursively for the right subtree.
        return min( abs(root->data-k) , minDiff(root->right, k) );
    }
