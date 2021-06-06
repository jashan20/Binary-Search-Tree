/*Given a Binary search tree and a value X,  the task is to complete the function which will return the floor of x.
Note: Floor(X) is an element that is either equal to X or immediately smaller to X. If no such element exits return -1. */
//Function to return the floor of given number in BST.
int floor(Node* root, int key) 
{ 
	// Your code goes here
	Node *res = NULL;
	while(root != NULL)
	{
	    if(root->data == key)
	    return key;
	    else if(root->data > key)
	    root = root->left;
	    else
	    {
	        res = root;
	        root = root->right;
	    }
	}
	if(res == NULL)
	return -1;
	return res->data;

}
